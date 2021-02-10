#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <vector>
#include "Time.cpp"
#include "Edge.cpp"
#include "Node.cpp"
#include "Graph.cpp"
#include <fstream>


using namespace std;

int main(int  argc, char* argv[]){
	string infile = argv[1];
//	string output = argv[2];
	Graph graph = Graph();

	ifstream i;
	i.open(infile);
	if(i.is_open()){
		string src;
		string dest;
		Time dep;
		Time arr;
		int price;
		string temp;

		while(i){
			getline(i,src,' ');
			if(src.empty()){
				break;
			}
//			cout<<"src: "<<src<<endl;
			getline(i,dest,' ');
//			cout<<"dest: "<<dest<<endl;
			getline(i,temp,' ');
//			cout<<"dep: "<<temp<<endl;
			dep = Time(temp);
//		       	cout<<"dep2: "<<dep<<endl;
			getline(i,temp,' ');
//			cout<<"arr: "<<temp<<endl;
			arr = Time(temp);
			getline(i,temp,'\n');
			temp.erase(0,1);
			price = stoi(temp); //still need to ommit the $
//			cout<<"price: "<<price<<endl;
			Edge *e = new Edge(src,dest, dep, arr,price);
			//cout<<*e<<endl;
			graph.addEdge(e);
		}
//		cout<<"------------------------------------------------"<<endl;
//		for(Node* temp1:graph.cities){
//			for(Edge* e: temp1->trans){
//				cout<<*e<<endl;
//			}
//		}
//		cout<<"------------------------------------------------"<<endl;
		Time* aa = new Time("08:00am");
		Time* test = new Time("12:00am");
//		if(*test<*aa){
//			cout<<"true"<<endl;
//		}
		Time* bb = new Time("10:41am");
		while(true){
			string from;
			string to;
			string option;
			Time dep;
			Time return_time;
			string temp;
			cout<<"Please select an option: Any, Earliest, or Exit"<<endl;
			cin>>option;
			if(option == "Any"){
				cout<<"Please enter the departure city name"<<endl;
				cin>>from;
				cout<<"Please enter the arrival city name"<<endl;
				cin>>to;
				graph.anyItinerary(from,to);
			}
			if(option == "Earliest"){
				cout<<"Please enter the departure city name"<<endl;
				cin>>from;
				cout<<"Please enter the arrival city name"<<endl;
				cin>>to;
				cout<<"Please enter the departure time"<<endl;
				cin>>temp;
				dep=Time(temp);
				cout<<"Please enter the return time"<<endl;
				cin>>temp;
				return_time=Time(temp);
				graph.earliestArrival(from, to, &dep, &return_time);
			}
			if(option == "Exit"){
				exit(0);
			}
		}
		graph.anyItinerary("binghamton","saudi");
		graph.anyItinerary("a", "e");
		graph.earliestArrival("binghamton","saudi",aa, bb);
	}
	return 0;
}
