#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include "structs.cpp"

using namespace std;

int seg_bit_size = 64;
int map_loc = 160;
int imap_size = 40;
//---------------- Log counters
char log[1024*1024];
int log_counter = 0;
//----------------- Map Counters
int map_count = 0;
map<string,int> file_map; //maps file name to inode number
//----------------- Function Protoypes
int import(string in, string out);
void remove(string file);
void cat(string file);
void display(string file, int howmany, int start);
void list();
void restart();
void shutdown();
//Global imap
imap* global_imap[40];
char cleanState[64];
//keeps track of current segment index and block number
int block_number=0;
int current_segment = 0;

void log_init(){
	for(int i=0; i<1024; i++){
		for(int j=0; j<1024; j++){
			log[i*1024+j] = '\0';
		}
	}
	block_number+=4;
	log_counter=4*1024;
}
void addToLog(char* x){
	memcpy(&log[log_counter], x, 1024);
	log_counter+=1024;
	if(log_counter == 1024*1024){
		//--------- OUTPUT TO DISK
		string o1 = "DRIVE/SEGMENT"+to_string(current_segment);
		ofstream segmentOut(o1);
		segmentOut.write(log,1024*1024);
		//---------
		log_init();
		ifstream in;
		in.open("DRIVE/CHECKPOINT_REGION");
		char dummy[224];
		in.read(dummy,224);
		char what = '1';
		memcpy(&dummy[current_segment],&what,1);
		in.close();
		ofstream outCheck("DRIVE/CHECKPOINT_REGION");
		outCheck.write(dummy,224);
		outCheck.close();
		cleanState[current_segment] = '1';
		current_segment++;
	}
}
inode* getInode(int blockNum){
	int segNum = blockNum/1024;
	int inSegNum = blockNum%1024;
	char inodeAsChar[1024];
	if(segNum == current_segment){
		memcpy(inodeAsChar, &log[inSegNum*1024],1024);
	}else{
		ifstream in;
		char temp_log[1024*1024];
		string fileName = "DRIVE/SEGMENT"+to_string(segNum);
		in.open(fileName);
		in.read(temp_log,1024*1024);
		memcpy(inodeAsChar, &temp_log[inSegNum*1024],1024);
	}
	inode* retVal = new inode;
	memcpy(retVal, inodeAsChar, 1024);
	return retVal;
}
int main(int argc, char* argv[]){    
	log_init();	
	restart();
	string input;
//	if(global_imap[0] != NULL){
//		cout<<"CURRENT SEG: "<<current_segment<<endl;
//		cout<<"FILE NAME: "<<global_imap[0]->arr[0]<<endl;
//	}
	while(true){
		cout<<"----------------------"<<endl;
		cout<<"Please specify which command you'd like to run: "<<endl;
		cout<<"import <filename> <lfs_filename>"<<endl;
		cout<<"remove <lfs_filename>"<<endl;
		cout<<"cat <lfs_filename>"<<endl;
		cout<<"display <lfs_filename> <howmany> <start>"<<endl;
		cout<<"list"<<endl;
		cout<<"shutdown"<<endl;
		cout<<"-----------------------"<<endl;

		getline(cin,input);
		stringstream ss;
		ss<<input;

		string in;
		string out;
		string command;
		ss>>command;

		if(command == "import"){
			ss>>in;
			ss>>out;
			int prob = import(in,out);
			if(prob==1){
				cout<<"File not found"<<endl;
				continue;
			}else if(prob==2){
				continue;
			}
			/*for(int i=0; i<1024*1024;i++){
				cout<<(char)log[i];
			}*/
			//cout<<endl;
		}else if(command == "remove"){
			ss>>in;
			remove(in);
		}else if(command == "cat"){

		}else if(command == "display"){

		}else if(command == "list"){
			list();
		}else if(command == "shutdown"){
			shutdown();
		}else{
			cout<<"Invalid command"<<endl;
			continue;
		}
	}
}
int imap_find(int map_num){
	ifstream infile;
	infile.open("DRIVE/CHECKPOINT_REGION");
	char original[224];
	int block_number;
	infile.read(original,224);
	memcpy(&block_number, &original[4*map_num+64], sizeof(int));     
	infile.close();
	return block_number;
}
imap* getMap(int blockNum){
	if(blockNum =='\0'){
		return NULL;
	}
	int segNum = blockNum/1024;
	int inSegNum = blockNum%1024;
	char imapAsChar[1024];
	if(segNum == current_segment){
		memcpy(imapAsChar, &log[inSegNum*1024],1024);
	}else{	
		ifstream in;
		char temp_log[1024*1024];
		string fileName = "DRIVE/SEGMENT"+to_string(segNum);
		in.open(fileName);
		in.read(temp_log,1024*1024);
		memcpy(imapAsChar, &temp_log[inSegNum*1024],1024);
		in.close();
	}
	imap* retVal = new imap;
	memcpy(retVal, imapAsChar, 1024);
	return retVal;
}
void check_update(int map_num, int block){
	ifstream infile;
	infile.open("DRIVE/CHECKPOINT_REGION");
	char original[224];
	infile.read(original,224);
	infile.close();
	memcpy(&original[4*map_num+64],&block,4);
	ofstream out;
	out.open("DRIVE/CHECKPOINT_REGION");
	out.write(original,224);
	out.close();
}
int import(string in, string out){
	//check if file is in file_map
	if(file_map.find(out)==file_map.end()){
		file_map[out] = map_count;
		map_count++; 
	}else{
		cout<<"file already exists"<<endl;
		return(-1);
	}
	ifstream infile;
	ofstream outfile;
	//--------------- Initialize Inode
	inode* temp_inode = new inode;
	temp_inode -> fileSize = 0;
	for(int i=0; i<out.length();i++){
		temp_inode->fileName[i] = out[i];
	}
	for(int i=out.length(); i<504;i++){
		temp_inode->fileName[i] = '\0';
	}
	temp_inode->current = 0;
	for(int i=0; i<128;i++){
		temp_inode->blockNums[i] = 0;
	}
	//FIND IMAP LOCATION
	int inode_num = file_map[out];
	int map_num = inode_num/256;
	int map_block = imap_find(map_num);
	//GET TO IMAP in Mem
	int seg = map_block/1024;
	imap im;
	global_imap[map_num] = &im;
	if(map_block == '\0'){
		for(int i=0; i<256;i++){
			im.arr[i] = 0;
		}
	}else{
		//GET IMAP
		ifstream imapRead;
		string x = "DRIVE/SEGMENT"+to_string(seg);
		imapRead.open(x);
		int inSegmentBlock = map_block%1024;
		//Get to the right point in the segment
		imapRead.seekg(inSegmentBlock*1024,imapRead.end);
		char imapFromFile[1024];
		//Read in imap bits
		imapRead.read(imapFromFile,1024);
		memcpy(&im,imapFromFile,1024); 
		imapRead.close();
	}
	//check if file is valid
	infile.open(in);
	if(infile.fail()){
		return 1;
	}
	//pull from input file
	else{
		//read in values from file
		char b1[1024];
		while(infile.read(b1, 1024)){
			if(b1[1023]!='\0'){
				temp_inode->fileSize+=1024;
			}
			memcpy(&log[log_counter], b1,1024);
			addToLog(b1);
			if(temp_inode->current<128){//if max number of data blocks for file is reached
				temp_inode->blockNums[temp_inode->current] = block_number;
				temp_inode->current++;
				block_number++;
			}else{
				cout<<"File too large"<<endl;
				return 1;
			}
			for(int i=0;i<1024;i++){
				b1[i]='\0';
			}
		}
		infile.close();
		if(b1[0]!='\0'){
			for(int i=0;i<1024;i++){
				if(b1[i] !='\0'){
					temp_inode->fileSize++;
				}else{
					break;
				}
			}
			addToLog(b1);
			if(temp_inode->current<=128){
				temp_inode->blockNums[temp_inode->current] = block_number;
				temp_inode->current++;
				block_number++;
			}else{
				cout<<"File too large"<<endl;
				return 1;
			}
		}
		//Inode to block
		char inodeToBlock[1024];
		memcpy(&inodeToBlock[0], temp_inode, sizeof(inodeToBlock));
		addToLog(inodeToBlock);
		im.arr[inode_num%256] = block_number;
		block_number++;
		check_update(map_num, block_number);
		//Imap to block
		char imapToBlock[1024];
		memcpy(&imapToBlock[0], &im, sizeof(imapToBlock));
		addToLog(imapToBlock);
		block_number++;
	}
	return 0;
}
void remove(string file){
	if(file_map.find(file)!= file_map.end()){
		int inodeNum = file_map[file];
		int map_num = inodeNum/256;
		int map_block = imap_find(map_num);
		//imap* im = getMap(map_block);
		imap* im = global_imap[map_num];
		im->arr[inodeNum%256] = -1;
		//Write out to SEGMENTS
		if(map_block/1024 != current_segment){
			string file2 = "DRIVE/SEGMENT"+to_string(map_block/1024);
			ifstream infile;
			infile.open(file2);
			char temp_log[1024*1024];
			infile.read(temp_log,1024*1024);
			memcpy(&temp_log[(map_block%1024)*1024], im , 1024);
			infile.close();
			ofstream outfile;
			outfile.open(file2);
			outfile.write(temp_log,1024*1024);
		}else{
			memcpy(&log[(map_block%1024)*1024], im,1024);
		}
		file_map[file]=-1;
	}
}
void cat(string file){

}
void display(string file, int howmany, int start){

}
void list(){
    /*Loop through every key in the file map*/
    map<string,int>::iterator it;

    for(it = file_map.begin(); it != file_map.end(); it++)
    {
        /*Get the iNode Number*/
        int iNodeNumber = it->second;

        /*Figure out which map the iNode is in by taking the iNodeNumber by 256*/
        int mapNum = iNodeNumber / 256;

        int mapBlockNum = imap_find(mapNum);

        //imap* im = getMap(mapBlockNum);
	    imap* im = global_imap[mapNum];

        /*Get the index into the imap by taking the iNodeNumber % 256*/
        int iMapIndex = iNodeNumber % 256;

        int iNodeBlockNum = im->arr[iMapIndex];

        /*Get the iNode*/
	cout<<"Inode block num: "<<iNodeBlockNum<<endl;
        inode* node = getInode(iNodeBlockNum);

        if(iNodeNumber!=-1){
		cout << it->first << " " << node->fileSize << endl;
	}
    }
}
void restart(){
	ifstream file_in;
	//string filename " " int iNodeNumber
	string mapperName="DRIVE/FILE_NAME_MAPPER";//always
	file_in.open(mapperName);
	string line;
	string f;
	int inodeNumber;
	while(getline(file_in,line)){
		stringstream s(line);
		s>>f>>inodeNumber;
		file_map[f] = inodeNumber;		
	}
	file_in.close();

	//ALL CHECKPOINT COPY	
	ifstream in;
	string fileName="DRIVE/CHECKPOINT_REGION";//always
	in.open(fileName);
	// 1=dirty,0=clean
	//GET CLEAN STATES
	in.read(cleanState,64);
	//FINDING CURRENT SEGMENT
	int findSeg=-1;
	for(int i=0;i<64;i++){
		if(cleanState[i]=='0'){
			findSeg=i;
			break;
		}
	}
	if(findSeg==-1){
		exit(0);
	}
	current_segment=findSeg;
	//GET LOG
	ifstream getLog("DRIVE/SEGMENT"+to_string(current_segment));
	getLog.read(log,1024*1024);
	//GET IMAP PIECES
	char dummy_checkpoint[160];
	in.read(dummy_checkpoint,160);
	int mapBlockSpot[40];
	//memcpy(mapBlockSpot,dummy_checkpoint,160);
	for(int i=0; i<40;i++){
		memcpy(&mapBlockSpot[i],&dummy_checkpoint[4*i],4);
		cout<<"Map Block Num: "<<mapBlockSpot[i]<<endl;
	}
	//import imap_pieces
	for(int i=0; i<40; i++){
		global_imap[i] = getMap(mapBlockSpot[i]);
	}
	in.close();
}
void shutdown(){
	ofstream out;
	string fileName = "DRIVE/SEGMENT"+to_string(current_segment);
	out.open(fileName);
	out.write(log, 1024*1024);
	out.close();

	ofstream outMap;
	string outFileMap="DRIVE/FILE_NAME_MAPPER";
	outMap.open(outFileMap);
	map<string,int>::iterator it;
	for(it = file_map.begin(); it != file_map.end(); it++)
	{
		string outString="";
		int oNum=it->second;
		string oName=it->first;
		outString= oName+" "+to_string(oNum);
		outMap<<outString<<endl;
	}
	outMap.close();
	exit(0);

}
