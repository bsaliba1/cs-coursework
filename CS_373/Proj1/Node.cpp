#include <vector>
#include <iostream>
#include <map>
#include <tuple>

using namespace std;
// Container class is a vector designed to hold all of the Nodes
class Container{
//Node class is designed to simulate the states of the automata
	public:
	class Node{
                char state;
                int number;
                map <char, tuple<Node*,char,char>> mp; //= new map<char,tuple<Node*,char,char>;//tuple holds the Node that is transitioned to, symbol change, and tape head direction 
            //NEEDS TO BE FIXED
            public:
                void addTransition(char sym1, Node* node,char sym2,char head){ 
			mp[sym1]=make_tuple(node,sym2,head);
		}
                  //NEEDS TO BE FIXED
                Node* transition (char sym, vector<char>* tape, int* pos){		
			if(mp.find(sym)==mp.end()){
				cout<<"No valid transition from node '"<<number<<"' given symbol '"<<sym<<"'"<<endl;
				exit(0);
				return nullptr;
			}
			tuple<Node*,char,char> tup = mp[sym];
			Node* retN = std::get<0>(tup);
			tape->at(*pos)= std::get<1>(tup);
			if(std::get<2>(tup)=='R'){
				if(*pos==tape->size()-1){
					tape->insert(tape->end(),'_');	
					tape->insert(tape->end(),'_');
				}
				*pos=*pos+1;
			}else{
				if(*pos==0){
					tape->insert(tape->begin(),'_');	
					tape->insert(tape->begin(),'_');
					*pos=*pos+1;
				}
				*pos=*pos-1;
			}
			return retN;	
                 }
                 int nodeNum(Node curr){
                     return number;
                 }
                 void assignState(char x){
                     if(x!='a' || x!='r'||x!='s'){
                         cout<<"assigning wrong state";
                     }else{
                         state = x;
                     }
                 }
                 char getState(){
                   return state;
                 }
                 Node(char st, int num){
                     state=st;
                     number=num;
                 }
                 int getNumber(){
                     return number;
                 }
		 Node(){
		 }
        };
    public:
         vector<Node*> nodeVec;
         int numNodes;
	 Container::Node* first;
         Container(){
             int numNodes=0;
             first = nullptr;
         }
         Node* get(int nodeNum){
             int i=0;
             for(vector<Node*>::iterator it=nodeVec.begin();it<nodeVec.end();it++){
                 Node* node = nodeVec.at(i);
                 if(node->getNumber()==nodeNum){
			return node;
                 }
                 i++;
             }
             return nullptr;
         }
         Node* newNode(char st,int num){
             Node *x = new Node(st,num);
             if(st=='s'){
                 first= x;
             }
	     nodeVec.push_back(x); 
             return x; 
         }
};

