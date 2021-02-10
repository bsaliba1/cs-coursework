#include "Voter.h"

Voter:: Voter(string lname,string fname,int a,int snumber,string sname,string t,string zcode){
	lastName = lname;
	firstName = fname;
	age = a;
	streetNumber = snumber;
	streetName = sname;
	town = t;
	zipCode = zcode;
	
	UserID();
	Passwd();
	donations = 0;
}
Voter:: Voter(string lname,string fname,int a,int snumber,string sname,string t,string zcode,string userid,string passwd,float dons){
	lastName = lname;
	firstName = fname;
	age = a;
	streetNumber = snumber;
	streetName = sname;
	town = t;
	zipCode = zcode;
	donations = 0;
	
	setUserID(userid);
	setPass(passwd);
	setDonations(dons);
}
Voter::Voter(){
	
}
void Voter::setUserID(string id){
	userid = id;
}
void Voter::setPass(string pass){
	password = pass;
}
void Voter::setDonations(float dons){
	donations = dons;
}
void Voter::execute_inner(){
	map<string,int> m={{"Update",1},{"Passwd",2},{"View",3},{"Donate",4},{"Report",5},{"Logout",6},{"Error",7}};
	bool x= true;
	while(x){
		string inp = getInput_inner();
		int option = m[inp];	
		switch(option){
			case 1 : Update();
				 continue;
					
			case 2 : Passwd();
				 continue;
			case 3 : View();
				 continue;
			case 4 : Donate();
				 continue;
			case 5 : Report();
				 continue;
			case 6 : x = false;
			case 7 : continue;
		}
	}
}
void Voter::Update(){
	string temp;
	cout<<"Please enter your last name:  "<<endl;
	getline(cin, lastName);	
	cout<<"Please enter your first name:  "<<endl;
	getline(cin, firstName);
	cout <<"Please enter your age:  "<<endl;
	getline(cin, temp);
	age = stoi(temp);
	cout<<"Please enter your street number:  "<<endl;
	getline(cin, temp);
	streetNumber = stoi(temp);
	cout<<"Please enter your street name:  "<<endl;
	getline(cin, streetName);
	cout<<"Please enter your town name:  "<<endl;
	getline(cin, town);
	cout<<"Please enter your zip code:  "<<endl;
	getline(cin, zipCode);
}
void Voter::Passwd(){
	string temp;
	bool x = true;
	while (x){
		cout<<"Note: Passwords must be:"<<endl;
		cout<<"\t - Between 6 and 10 character";
		cout<<"\t - At least 1 digit";
	       	cout<<"\t - At least 1 letter";
		cout<<"\t - Exactly one character that is not a letter or digit"<<endl;
		cout<<"Please enter a valid password:  ";
		getline(cin,temp);
		bool conditions_met = true;
		bool has_digit=false;
		bool has_letter=false;
		bool has_other=false;
		if(temp.length()<10 and temp.length()>6){
			for(int i=0;i<temp.length();i++){
				if(isalpha(temp[i])){
					has_letter=true;
				}
				if(isdigit(temp[i])){
					has_digit=true;
				}else{
					has_other=true;
				}
			}
		}if(!(has_digit and has_letter and has_other)){
			conditions_met = false;
		}
		if(!conditions_met){
			cout<<"Conditions not met"<<endl;
			continue;
		
		}else{
			password = temp;
			x = false;
		}
	}		
}
void Voter::UserID(){
	string temp;
	bool x = true;
	while (x){
		cout<<"Note: UserIds must be between 5 and 10 character and must only consist of letters and digits"<<endl;
		cout<<"Please enter a userID: ";
		getline(cin,temp);
		bool conditions_met= true;
		if(temp.length()<10 and temp.length()>5){
			for(int i=0;i<temp.length();i++){
				if(!isalpha(temp[i])and!isdigit(temp[i])){
					cout<<"Invalid userID"<<endl;
					conditions_met = false;
				}	
			}
		}
		if(!conditions_met){
			cout<<"Conditions not met"<<endl;
			continue;
		}else{
			userid = temp;
			x=false;
		}
	}
}
void Voter::View(){
	cout<<endl;
	cout<<"Last Name: "<<lastName<<endl;
	cout<<"First Name: "<< firstName<<endl;
	cout<<"UserID: "<< userid<<endl;
	cout<<"Age: "<<age<<endl;
	cout<<"Street Number: "<<streetNumber<<endl;
	cout<<"Street: "<<streetName<<endl;
	cout<<"Town: "<<town<<endl;
	cout<<"Zip Code: "<<zipCode<<endl;
	cout<<"Donation Amount: "<<donations<<endl;	
	cout<<endl;
}
void Voter::Donate(){
	cout<<"Please enter the amount you would like to donate:  "<<endl;
	string temp;
	getline(cin,temp);;
	float temp1 = stof(temp);
	donations=donations+temp1;
}
void Voter::Report(){
	cout<<lastName<<": $"<<donations<<endl;
}
string Voter::getInput_inner(){
	string inp;
	string valid[]={"Update","Passwd","View","Donate","Report","Logout"};
	cout<<"Please enter a command: \n\n";
	cout<<"Update: Update voter information \n";
	cout<<"Passwd: Change password \n";
	cout<<"View: Display voter information\n";
	cout<<"Donate: Make a donation to the campaign \n";
	cout<<"Report: Display the voter last name as well as campaign contributions \n";
	cout<<"Logout: Logout of voter account\n\n";

	getline(cin,inp);
	for(int i=0;i<(sizeof(valid)/sizeof(valid[0]));i++){
		if(inp==valid[i]){
			return inp;
		}
	}

	cout<<"Please enter a valid command"<<endl;
	return "Error";
}
string Voter::getUserID(){
	return userid;
}
string Voter::getPasswd(){
	return password;
}

