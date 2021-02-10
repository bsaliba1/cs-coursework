#include <iostream>
#include <string>
#include <iomanip>
#include "linker.h"
using namespace std;
//NOTE: Can also pass pointers by initializing a value(ex: string examp1;) outside the functionand then have the function param be &<varName>. This allows you to treat this var as if it was initialized in this function while also being able to access it's value outside the function. 

void aNew(string* lastName,string* firstName,int* age,int* streetNumber,string* streetName,string* town,string* zipCode,float* donationAmount){
	cout<<"\nPlease enter your last name:  ";
	cin.ignore();
	getline(cin,*lastName);
	cout<<"\nPlease enter your first name:  ";
	cin>> *firstName;
	cout<<"\nPlease enter your age:  ";
	cin>> *age;
	cout<<"\nPlease enter your street number:  ";
	cin>> *streetNumber;
	cout<<"\nPlease enter your street name:  ";
	cin.ignore();
	getline(cin,*streetName);
	cout<<"\nPlease enter your town's name:  ";
	getline(cin,*town);
	cout<<"\nPlease enter your zip code:  ";
	cin>> *zipCode;
	*donationAmount=0.00;	
}

void update(string* lastName,string* firstName,int* age,int* streetNumber,string* streetName,string* town,string* zipCode){
	cout<<"\nPlease enter your last name:  ";
	cin>> *lastName;
	cout<<"\nPlease enter your first name:  ";
	cin>> *firstName;
	cout<<"\nPlease enter your age:  ";
	cin>> *age;
	cout<<"\nPlease enter your street number:  ";
	cin>> *streetNumber;
	cout<<"\nPlease enter your street name:  ";
	cin.ignore();
	getline(cin,*streetName);	
	cout<<"\nPlease enter your town's name:  ";
	getline(cin,*town);	
	cout<<"\nPlease enter your zip code:  ";
	cin>> *zipCode;
}

void view(string* lastName,string* firstName,int* age,int* streetNumber,string* streetName,string* town,string* zipCode,float* donationAmount){
	cout<<"\nYour last name is: "<<*lastName;
	cout<<"\nYour first name is: "<<*firstName;
	cout<<"\nYour age is: "<<*age;
	cout<<"\nYour street number is: "<<*streetNumber;
	cout<<"\nYour street name is:  "<<*streetName;
	cout<<"\nYour town's name is: "<<*town;
	cout<<"\nYour zipcode is: "<<*zipCode;
	float donation = *donationAmount;
	cout<<"\nYour current balance to date is: "<<fixed<<setprecision(2)<<donation<<endl;
}
void donate(float* donationAmount){
	float donation;
	cout<<"\nPlease enter the amount you would like to donate:  ";
	cin>>donation;
	*donationAmount=*donationAmount+donation;
}
void report(string* lastName, float* donationAmount){
	cout<<"\n"<<*lastName<<" $"<<*donationAmount;
}
