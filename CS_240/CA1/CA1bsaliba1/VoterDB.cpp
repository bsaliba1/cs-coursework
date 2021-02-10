#include "linker.h"
#include <iostream>

using namespace std;

int getInput(){
	
	string retVal;
	string validInp[]={"New","Update","View","Donate","Report","Quit"};

	cout << "Please type one of the following commands depending on what you'd like to do: \n";
	cout << "- 'New': Zero out all passed values \n";
	cout << "- 'Update': Update user information \n";
	cout << "- 'View': Display all user information \n";
	cout << "- 'Donate': Donate to the campaign \n";
	cout << "- 'Report': Display last name and current donation balance \n";
	cout << "- 'Quit': Exit program \n";

	cin >> retVal;
	//check if input is a valid input
	for(int i=0;i<(sizeof(validInp)/sizeof(validInp[0]));i++){
	       if(retVal == validInp[i])return i;	
	}
	//if the program gets to this point then it is an invalid input so thus rerun getInput()
	cout<< "Invalid input \n";
	return getInput();
}
//executes inputted command	
void execute(int inp,string *lastName,string* firstName,int *age,int *streetNumber,string *streetName,string *town,string *zipCode,float *donationAmount){
	switch(inp){
	// NEW
		case 0: aNew(lastName,firstName,age,streetNumber,streetName,town,zipCode,donationAmount);
			    break;
	// UPDATE
		case 1: update(lastName,firstName,age,streetNumber,streetName,town,zipCode);
			       break;
	 //VIEW
		case 2: view(lastName,firstName,age,streetNumber,streetName,town,zipCode,donationAmount);
			     break;
	// DONATE
		case 3: donate(donationAmount);
			       break;
	// REPORT	
		case 4: report(lastName,donationAmount);
			       break;
	// QUIT
		case 5: exit(EXIT_SUCCESS);
			     break;
	}
}

int main(int argc, char *argv[]){
	string* lastName= new string();
	string* firstName= new string();
	int* age=new int();
	int* streetNumber=new int();
	string* streetName=new string();
	string* town=new string();
	string* zipCode=new string();
	float* donationAmount=new float(0.00);
	int inp;
	

	//fetches input and executes that input command untill user inputs Quit
	bool isfirst = 1;
	while(inp!=5){
		if(!isfirst){
			cout<<"\nInputted command has been executed. What would you like to do next?? \n\n";	
		}
		inp = getInput();
		execute(inp,lastName,firstName,age,streetNumber,streetName,town,zipCode,donationAmount);
		isfirst=0;
	}	
}
