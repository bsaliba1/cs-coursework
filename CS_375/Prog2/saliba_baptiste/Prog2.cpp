#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include "Graph.cpp"

using namespace std;

typedef struct item{
	int weight;
	int price;	
	
}item;

bool pwratio (item* i,item* j) {
	return ((i->price/i->weight) > (j->price/j->weight));
}
bool price (item* i, item* j){
	return (i->price>j->price);
}
bool weight (item*i, item*j){
	return (i->weight>j->weight);
}

float estimate(vector<item*> list, int index, int cap){
	float retVal = 0;
	if(cap<=0){
		return 0;
	}
	while(cap!=0 && index<list.size()){
		if(list[index]->weight>=cap){
			retVal += cap*((list[index]->price)/(list[index]->weight));
			return retVal;
		}else{
			retVal += list[index]->price;
			cap = cap-list[index]->weight;
			index++;
		}
	}
	return retVal;
}

void printusage(){
	fprintf(stderr,"./prog2 <inputfile> <outputfile>\n");
	return;
}
void knapsack(int n, const vector<item*> list, int W, int max_profit, ofstream& outfile);
vector<int> optimal;
int main(int argc, char* argv[]){

	int capacity;
	int size_problem;
	ifstream infile;
	ofstream outfile;
	vector<item*> list;

	if(argc != 3){
		fprintf(stderr, "Must be two command line arguments\n");
		printusage();
	}else{	
		infile.open(argv[1]);
		outfile.open(argv[2]);
	}

	//Create list of items
	string line;
	if (infile.is_open()){
		int count=0;
		while ( getline (infile,line) ){//while still has lines 
			if(count==0){
				string num;//concatenates the int chars in the string
				for(int i=0; i<line.length();i++){
					if(line[i]!=','){
						num+=line[i];//concatenate ints as long as not ','
					}else{
						size_problem = stoi(num);//change from string to int
						num = "";//reset num knowing that you reached the end of that number
					}
				}
				capacity = stoi(num);
				count++;
			}else{	
				//create item here
				string num;//concatenates the int chars in the string
				item* temp;//create item to be added to the list of items
				int w;//will be the new items weight
				int p;//will be the new items price
				for(int i=0; i<line.length();i++){
					if(line[i]!=','){
						num+=line[i];//concatenate ints as long as not ','
					}else{
						w = stoi(num);//change from string to int
						temp = new item;
						temp ->weight = w;
						num = "";//reset num knowing that you reached the end of that number
					}
				}
				p = stoi(num);
				temp->price = p;
				list.push_back(temp);
			}
		}
		infile.close();
	}

	else cout << "Unable to open file"<<endl;

	sort(list.begin(),list.end(),pwratio);//sorts vector based on pw ratio
		
	int max_profit = 0;
	knapsack(size_problem, list, capacity, max_profit, outfile);  
	outfile.close();
	return 0;
}
void knapsack(int n, const vector<item*> list, int W, int max_profit, ofstream& outfile){
	max_profit = 0;
	int optsize=0;
	int numNodes=1;
	int numLeaves=0;
	priority_queue<Node> Q;
	
	//start node
	Node u,v;
	v.value = 0; v.level = 0; v.weight = 0;
	v.estimate = estimate(list,v.level,W);

	Q.push(v);

	while(!Q.empty()){
		v=Q.top();
		Q.pop();
		if(v.estimate>max_profit){
			numNodes += 2;
			u.level = v.level+1;
			//yes child
			u.weight = v.weight+list[v.level]->weight;
			u.value = v.value+list[v.level]->price;
			u.k = v.k;
			u.k.push_back(v.level);
			if((u.weight <= W) and (u.value>max_profit)){
				max_profit = u.value;
				optimal = u.k;
			}
			u.estimate = u.value + estimate(list,u.level,W-u.weight);
			if(u.estimate>max_profit && u.weight<W){
				Q.push(u);
			}else{
				numLeaves++;
			}
			//no child
			u.weight = v.weight;
			u.value = v.value;
			u.k = v.k;
			u.estimate =  u.value + estimate(list, u.level, W-u.weight);
			if(u.estimate>max_profit && u.weight<W){
				Q.push(u);
			}else{
				numLeaves++;
			}
		}else{
			numLeaves++;
		}
	}
	optsize = optimal.size();
	outfile << n << "," << max_profit << "," << optsize << endl << numNodes << "," << numLeaves << endl;
	for(int i=0; i<optimal.size();i++){
		outfile<<list[optimal[i]]->weight<<","<<list[optimal[i]]->price<<endl;
	}
}
