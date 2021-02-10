#include <vector>
#include <algorithm>
#include "LLC.h"
#include <iostream>
using namespace std;

LLC::LLC(){
	first =nullptr;
	last=nullptr;
	numNodes=0;
}
LLC::LLC(LLC *to_copy){
	LLC::Node *it = to_copy->first;
	numNodes=0;
	while(it!=nullptr){
		insert(it->data);
		it=it->next;
	}
}
LLC::Node* LLC::insert(const string str){
	Node* new_node;
	if(numNodes==0){
		new_node= new Node(str);
		first = new_node;
		last = new_node;
		last->next=nullptr;
	}else{
		new_node= new Node(str);
		last->next = new_node;
		last = new_node;
		last->next = nullptr;
	}
	numNodes++;
	return new_node;
}	
LLC::Node::Node(){
	
}
LLC::Node::Node(string str){
	data =str;
}
LLC::Node::Node(Node* node){
	data=node->data;
}
LLC::~LLC(){
	if(numNodes<2){
		delete(first);
	}else if(numNodes==2){
		delete(first);
		delete(last);
	}else{
		LLC::Node *temp = first;
		while(temp!=nullptr){
			LLC::Node* temp2=temp;
			temp= temp->next;
			delete(temp2);
		}
	}
	return;
}
void LLC::remove(string val){
	if(numNodes==0){
		cout<<"No nodes in LLC";
	}
	if(numNodes==1){
		if(first->data==val){
			LLC::Node *temp =first;
			first=nullptr;
			delete(temp);
		}	
	}
	if(numNodes==2){
		if(first->data==val){
			LLC::Node *temp=first;
			first=last;
			delete(temp);
		}if(last->data==val){
			LLC::Node *temp =last;
			last=first;
			delete(temp);
		}
	}else{
		LLC::Node *it=first;
		LLC::Node *before;
		while(it!=nullptr){
			if(it->data==val){
				LLC::Node *temp = it;
				if(it->next==nullptr){
					last=before;
					delete(it);
				}else if(it==first){
					first = it->next;
					delete(it);
				}else{
					before->next=it->next;
					delete(temp);
				}
			}
			before=it;
			it=it->next;
		}
	}
	numNodes--;

}
bool LLC::contains(const string val){
	bool retval = false;
	LLC::Node *it= first;
	while(it!=nullptr){
		if(it->data==val){
			retval=true;
		}
		it=it->next;
	}
	return retval;
}
int LLC::len(){
	return numNodes;
}
void LLC::shuffle(){
	vector<string> vec;
	LLC::Node *curr = first;
	for(int i=0;i<numNodes;i++){
		vec.push_back(curr->data);
		curr = curr->next;
	}
	random_shuffle(vec.begin(),vec.end());
	curr=first;
	for(int i=0;i<numNodes;i++){
		curr->data=vec.at(i);
		curr=curr->next;
	}
}
string LLC::tail(){
	cout<<last->data<<endl;
	return last->data;
}
LLC LLC::operator=(const LLC& list){
	LLC::Node *temp4=first;
	LLC::Node *x;
	while(temp4!=nullptr){
		x=temp4->next;
		delete(temp4);
		numNodes--;
		temp4=x;
	}
	LLC::Node *temp = list.first;
	while(temp!=nullptr){
		insert(temp->data);
		temp=temp->next;
	}
	return this;	
}
LLC LLC::operator+(const LLC& list){
	LLC* result=new LLC();
	LLC::Node *temp = first;
	while(temp!=nullptr){
		result->insert(temp->data);
		temp = temp->next;
	}
	temp = list.first;
	while(temp!=nullptr){
		if(temp->next==nullptr){
			result->last=result->insert(temp->data);
			break;
		}
		result->insert(temp->data);
		temp = temp->next;
	}
	return *result;
}
void LLC::head(int n){
	if(n>numNodes){
		cout<<"Parameter for head function is too large"<<endl;
		n = numNodes;
	}
	LLC::Node *temp=first;
	//first print [(first),
	cout<<"["<<temp->data<<",";
	temp=temp->next;
	for(int i=1;i<n-1;i++){
		//for each node in list print ... (data),
		cout<<" "<<temp->data<<",";
		temp=temp->next;
	}
	//last print ... (last)]
	cout<<" "<<temp->data<<"]"<<endl;
}
LLC& LLC::operator+=(int n){
	for(int i=0;i<n;i++){
		LLC::Node *temp=first;
		first=temp->next;
		last->next=temp;
		last = last->next;
		last->next=nullptr;
	}
	return *this;
}
void LLC::join(const LLC& other){
	LLC::Node *temp=other.first;
	for(int i=0;i<other.numNodes;i++){
		insert(temp->data);
		temp=temp->next;
	}
	
}
ostream& operator<<(ostream& os, LLC* list){
	if(list->len()!=0){
		LLC::Node *temp=list->first;
		os<<"["<<temp->data<<",";
		temp=temp->next;
		for(int i=1;i<list->len();i++){	
			if(i!=list->len()-1){
				os<<" "<<temp->data<<",";
				temp=temp->next;
			}else{
				os<<" "<<temp->data;
				temp=temp->next;
			}
		}
		os<<"]";
	}else{
		os<<"[]";
	}
	return os;
}	
