#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename ElementType>
LLC<ElementType>::LLC(){
	first =nullptr;
	last=nullptr;
	numNodes=0;
}

template <typename ElementType>
LLC<ElementType>::LLC(LLC *to_copy){
	LLC<ElementType>::Node *it = to_copy->first;
	numNodes=0;
	while(it!=nullptr){
		insert(it->data);
		it=it->next;
	}
}

template <typename ElementType>
typename LLC<ElementType>::Node* LLC<ElementType>::insert(const ElementType str){
	LLC<ElementType>::Node* new_node;
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

template <typename ElementType>
LLC<ElementType>::Node::Node(){
	
}

template <typename ElementType>
LLC<ElementType>::Node::Node(ElementType str){
	data =str;
}

template <typename ElementType>
LLC<ElementType>::Node::Node(Node* node){
	data=node->data;
}

template <typename ElementType>
LLC<ElementType>::~LLC(){
	if(numNodes<2){
		delete(first);
	}else if(numNodes==2){
		delete(first);
		delete(last);
	}else{
		LLC<ElementType>::Node *temp = first;
		while(temp!=nullptr){
			LLC<ElementType>::Node* temp2=temp;
			temp= temp->next;
			delete(temp2);
		}
	}
	return;
}

template <typename ElementType>
void LLC<ElementType>::remove(ElementType val){
	if(numNodes==0){
		cout<<"No nodes in LLC";
	}
	if(numNodes==1){
		if(first->data==val){
			LLC<ElementType>::Node *temp =first;
			first=nullptr;
			delete(temp);
		}	
	}
	if(numNodes==2){
		if(first->data==val){
			LLC<ElementType>::Node *temp=first;
			first=last;
			delete(temp);
		}if(last->data==val){
			LLC<ElementType>::Node *temp =last;
			last=first;
			delete(temp);
		}
	}else{
		LLC<ElementType>::Node *it=first;
		LLC<ElementType>::Node *before;
		while(it!=nullptr){
			if(it->data==val){
				LLC<ElementType>::Node *temp = it;
				if(temp->next==nullptr){
					last=before;
					delete(temp);
				}else if(it==first){
					first = temp->next;
					delete(temp);
				}else{
					before->next=temp->next;
					delete(temp);
				}
			}
			before=it;
			it=it->next;
		}
	}
	numNodes--;

}

template <typename ElementType>
bool LLC<ElementType>::contains(const ElementType val){
	bool retval = false;
	LLC<ElementType>::Node *it= first;
	while(it!=nullptr){
		if(it->data==val){
			retval=true;
		}
		it=it->next;
	}
	return retval;
}

template <typename ElementType>
int LLC<ElementType>::len(){
	return numNodes;
}

template <typename ElementType>
void LLC<ElementType>::shuffle(){
	vector<ElementType> vec;
	LLC<ElementType>::Node *curr = first;
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
template <typename ElementType>
ElementType LLC<ElementType>::tail(){
	cout<<last->data<<endl;
	return last->data;
}

template <typename ElementType>
LLC<ElementType> LLC<ElementType>::operator=(const LLC<ElementType>& list){
	LLC<ElementType>::Node *temp4=first;
	LLC<ElementType>::Node *x;
	while(temp4!=nullptr){
		x=temp4->next;
		delete(temp4);
		numNodes--;
		temp4=x;
	}
	LLC<ElementType>::Node *temp = list.first;
	while(temp!=nullptr){
		insert(temp->data);
		temp=temp->next;
	}
	return this;	
}

template <typename ElementType>
LLC<ElementType> LLC<ElementType>::operator+(const LLC& list){
	LLC<ElementType> result1= LLC();
	LLC<ElementType>* result = &result1;
	LLC<ElementType>::Node *temp = first;
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
	cout<<result<<endl;
	return *result;
}

template <typename ElementType>
void LLC<ElementType>::head(int n){
	if(n>numNodes){
		cout<<"Parameter for head function is too large"<<endl;
		n = numNodes;
	}
	LLC<ElementType>::Node *temp=first;
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

template <typename ElementType>
LLC<ElementType>& LLC<ElementType>::operator+=(int n){
	for(int i=0;i<n;i++){
		LLC<ElementType>::Node *temp=first;
		first=temp->next;
		last->next=temp;
		last = last->next;
		last->next=nullptr;
	}
	return *this;
}

template <typename ElementType>
void LLC<ElementType>::join(const LLC<ElementType>& other){
	LLC<ElementType>::Node *temp=other.first;
	//cout<<other.numNodes<<endl;
	for(int i=0;i<other.numNodes;i++){
		insert(temp->data);
		temp=temp->next;
	}
	
}

template <typename ElementType>
ostream& operator<<(ostream& os, LLC<ElementType>* list){
	if(list->len()!=0){
		typename LLC<ElementType>::Node *temp=list->first;
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
