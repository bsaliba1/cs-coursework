#include <iostream>
#include <string.h>
#include <map>
using namespace std;

class Voter{
	public: 
		Voter();
		Voter(string lname,string fname,int a,int snumber,string sname,string t,string zcode);
		Voter(string lname,string fname,int a,int snumber,string sname,string t,string zcode,string userid,string passwd,float dons);

	private:
		string userid;
		string password;
	public:
		string lastName;
		string firstName;
		int age;
		int streetNumber;
		string streetName;
		string town;
		string zipCode;
		float donations;

		void execute_inner();
		void Update();
		void Passwd();
		void UserID();
		void View();
		void Donate();
		void Report();
		string getInput_inner();
		string getUserID();
		string getPasswd();
		void setUserID(string id);
		void setPass(string pass);
		void setDonations(float dons);
};
