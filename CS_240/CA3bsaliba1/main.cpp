#include <iostream>
#include <string>
#include "LLC.h"

using namespace std;

int main(){
	//Note: (1) means the test works and (0) means it doesn't
	LLC *def_list = new LLC();//test default constructor (1)

	//test insert (1)
	cout<<endl<<"List before inserting: "<<def_list<<endl;
	def_list->insert("lemon");
	def_list->insert("apple");
	def_list->insert("lime");
	def_list->insert("pineapple");
	cout<<"\nList after inserting (lemon, apple, lime, and pineapple) : "<<def_list<<endl;

	cout<<"\nThe length of this line should be 4 and is: "<<def_list->len()<<endl;
	
	cout<<"\nList contains apple so it should return (1) for true and it returns: "<<def_list->contains("apple")<<endl;//test contains function (1)
	
	cout<<"\nHead(2) test: ";
	def_list->head(2);//test head function (1)
	
	cout<<"\nBefore shuffle "<<def_list;
	def_list->shuffle();//test shuffle function (1)
	cout<<" After shuffle "<<def_list<<endl;

	LLC *cop_list= new LLC();
	
	*cop_list = *def_list;//test operator =  (1)

	LLC *cop_list2 = new LLC(def_list);//test copy constructor (1)
	
	cout<<"\nTo_copy list: "<<def_list<<", Copied list: "<<cop_list2<< endl;

	delete(def_list);

	cout<<"\nBefore +=2: "<<cop_list2;
	*cop_list2+=2;//+= operator test (0)
	cout<<" After +=2: "<<cop_list2<<endl;	

	cout<<"\nBefore remove 'apple': "<<cop_list2;
	cop_list2->remove("apple");
	cout<<"After: "<<cop_list2<<endl;
	
	LLC *list1=new LLC();	
	list1->insert("banana");
	*list1=*cop_list+*cop_list2;
	cout<<"\nAdding "<<cop_list<<" and "<<cop_list2<<" = "<<list1<<endl;

	cop_list2->join(*cop_list);
	cout<<"\nJoining "<<cop_list2<<" and "<<cop_list<<" = "<<cop_list2<<endl<<endl;

	return 0;
}
