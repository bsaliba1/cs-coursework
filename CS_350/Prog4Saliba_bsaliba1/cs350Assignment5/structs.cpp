using namespace std;

typedef struct imap{
    int arr[1024/4];
}imap;
void init_block(char* b){
    for(int i=0; i<1024;i++){
        b[i] = '\0';
    }
}
typedef struct inode{
    char fileName[504];
    int fileSize;
    int current;
    int blockNums[128];
}inode;
void putInode(int blockNum, inode* inodeToPut){
	int segNum = blockNum/1024;
	int inSegNum = blockNum%1024;
	ifstream in;
	string fileName = "DRIVE/SEGMENT"+to_string(segNum);
	in.open(fileName);
	char seg[1024*1024];
	in.read(seg,1024*1024);
	in.close();
	ofstream out;
	out.open(fileName);
	memcpy(&seg[inSegNum*1024], inodeToPut, 1024);
	out.write(seg,1024*1024);
}
