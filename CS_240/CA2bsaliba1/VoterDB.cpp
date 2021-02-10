#include "VoterDB.h"
#include <fstream>
#include <iostream>
#include <iomanip>

void VoterDB::execute_outer(){
	map<string,int> m={{"Login",1},{"New",2},{"Report",3},{"Save",4},{"Load",5},{"Quit",6},{"Error",7}};
	bool x = true;
	while(x){
		string inp = getInput_outer();
		int option = m[inp];
		switch(option){
			case 1 : Login();
				 continue;
			case 2 : New();
				 continue;
			case 3 : Report();
				 continue;
			case 4 : Save();
				 continue;
			case 5 : Load();
				 continue;
			case 6 : Quit();
			case 7 : continue;
		}
	x=true;
	cout<<"x set to true"<<endl;
	}
}
string VoterDB::getInput_outer(){
	string inp;
	string valid[]={"Login","New","Report","Save","Load","Quit"};
	cout<<"\nPlease enter a command: \n\n";
	cout<<"Login: Login to voter account \n";
	cout<<"New: Create new voter account \n";
	cout<<"Report: Display all voter information \n";
	cout<<"Save: Save voter database to a file \n";
	cout<<"Load: Load all voter information from a file \n";
	cout<<"Quit: Quit program \n\n";

	getline(cin, inp);
	for(int i=0;i<(sizeof(valid)/sizeof(valid[0]));i++){
		if(inp==valid[i]){
			return inp;
		}
	}
	cout<<"Please enter a valid command"<<endl;
	return "Error";
}
VoterDB::VoterDB(int maxsize){
	voterdb = new Voter[maxsize];
}
int VoterDB::Login(){
	string temp;
	Voter voter_match;
	if(numvoters ==0){
		cout<<"No voters in database. Create new voter before logging in"<<endl;
	}
	cout<<"Please enter your userID:  ";
	getline(cin, temp);
	bool match = false;
	for(int i=0;i<numvoters;i++){
		if(voterdb[i].getUserID()==temp){
			match =true;
			voter_match = voterdb[i];
		}
	}
	if(!match){
		cout<<"UserID doesn't match"<<endl;
	}else{
		int i=0;
		bool match =false;
		cout<<"Note you have 3 tries to enter your password"<<endl;	
		while(i<3 and !match){		
			string temp_pass;
			cout<<"Please enter your password:  ";
			getline(cin,temp_pass);
			if(temp_pass == voter_match.getPasswd()){
				match = true;
			}
			i++;
		}
		if(match){
			cout<<"**Login successful**"<<endl;
			voter_match.execute_inner();
		}
	}
}
void VoterDB::New(){
	
	Voter *voter = new Voter();
	voter->UserID();
	voter->Passwd();
	voter->Update();
	voterdb[numvoters]= *voter;
	numvoters++;
	cout<<"Num voters incremented"<<endl;
}
void VoterDB::Report(){
	if(numvoters==0){
		cout<<"\n-----No voters in database-----"<<endl;
	}else{
		for(int i=0;i<numvoters;i++){
			voterdb[i].View();
		}
	}
}
void VoterDB::Save(){
	string filename;
	bool x= true;
	while(x){	
		cout<<"Please enter the name of the file you'd like to write to:  ";
		getline(cin,filename);
		if(ifstream(filename.c_str())){
			string temp;
			cout<<"File already exists. Do you want to override (type 'y'=yes and 'n'=no): ";
			getline(cin,temp);
			if(temp=="y"){
				ofstream file;
			       	file.open(filename.c_str());
				file<<numvoters<<endl;
				for(int i=0;i<numvoters;i++){
					file<<voterdb[i].lastName<<",";
					file<<voterdb[i].firstName<<",";
					file<<voterdb[i].age<<",";
					file<<voterdb[i].streetNumber<<",";
					file<<voterdb[i].streetName<<",";
					file<<voterdb[i].town<<",";
					file<<voterdb[i].zipCode<<",";
					file<<voterdb[i].getUserID()<<",";
					file<<voterdb[i].getPasswd()<<",";
					file<<voterdb[i].donations<<endl;
			
				}
			x=true;
			break;
			}else{
				continue;
			}
		}else{
			ofstream file;
		       	file.open(filename.c_str());
			file<<numvoters<<endl;
			for(int i=0;i<numvoters;i++){
				file<<voterdb[i].lastName<<",";
				file<<voterdb[i].firstName<<",";
				file<<voterdb[i].age<<",";
				file<<voterdb[i].streetNumber<<",";
				file<<voterdb[i].streetName<<",";
				file<<voterdb[i].town<<",";
				file<<voterdb[i].zipCode<<",";
				file<<voterdb[i].getUserID()<<",";
				file<<voterdb[i].getPasswd()<<",";
				file<<voterdb[i].donations<<endl;
		
			}
			x=true;
			break;
		}
	}
}
void VoterDB::Load(){
	string filename;
	cout<<"Please enter the name of the file you would like to load from: ";
	getline(cin, filename);
	ifstream file;
	file.open(filename.c_str()); 
	
	string lastname;
	string firstname;
	int age;
	int streetnum;
	string streetname;
	string town;
	string zipcode;
	string userid;
	string passwd;
	float donations;

	string temp;
	int i=numvoters;
	int x;
	getline(file,temp);
	x= stoi(temp);	
	while(!file.eof()){
		getline(file,lastname,',');
		getline(file,firstname,',');
		getline(file,temp,',');
		age = stoi(temp);
		getline(file,temp,',');
		streetnum = stoi(temp);
		getline(file,streetname,',');
		getline(file,town,',');
		getline(file,zipcode,',');
		getline(file,userid,',');
		getline(file,passwd,',');		
		getline(file,temp,'\n');
		donations = stof(temp);
		file.ignore();
		cout<<"adding new voter"<<endl;
		
		Voter* voter = new Voter(lastname,firstname,age,streetnum,streetname,town,zipcode,userid,passwd,donations);
		voterdb[i]=*voter;
		numvoters++;
		i++;
	}

}
void VoterDB::Quit(){
	exit(0);
}
