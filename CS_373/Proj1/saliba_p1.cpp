#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Node.cpp"
using namespace std;

string execute(string input,vector<char> tape,Container* cont,int maxnumber){    
    //enter input into the vector
    	tape.push_back('_');
	for(int i=0; i<input.length();i++){
         	tape.push_back(input[i]);
  	}
	tape.push_back('_');
  	Container:: Node *first= cont->first;
  	//put in while loop with counter for max number of transitions
	int nums =0;
	int i =1;
	while(bool x=true){
  	      char c = tape.at(i);
  	      if(nums==maxnumber){
		      cout<<cont->first->getNumber()<<" ";	
		      return "quit";
	      }if(cont->first->getState()=='a'){
	      	      cout<<cont->first->getNumber()<<" ";	
		      return "accept";
	      }if(cont->first->getState()=='r'){	
	      	      cout<<cont->first->getNumber()<<" ";	
		      return "reject";
	      }
	      cout<<cont->first->getNumber()<<"->"; 
	      Container:: Node* curr =  cont->first->transition(c,&tape,&i); 
	      cont -> first = curr;   
	      nums++;
	}	      
	return "Error";
}
void getinp(ifstream* input,char* iftrans,char* state,int* nodeNum,char* before,int* transNode, char* after, char* point ){
    string line; 
    getline(*input,line,'\t');
    string temp;
    if(line=="state"){
        *iftrans = 's';
        //get nodeNum
        getline(*input, temp,'\t');
        *nodeNum = stoi(temp);
        getline(*input, temp , '\n');
        //accpet,reject, or start state
      	*state = temp[0];
    } 
    else{
        *state='n';
        *iftrans = 't';
        //nodenum
        getline(*input, temp,'\t');
        *nodeNum = stoi(temp);
        //sym before
        getline(*input,temp,'\t');
        *before = temp.at(0);
        //get transnode num
        getline(*input, temp, '\t');
	*transNode = stoi(temp);
        //sym after
        getline(*input,temp,'\t');
	*after = temp[0];
        //move point head left or right
        getline(*input,temp,'\n');
        *point = temp[0];
        input->ignore();
    }
}

int main(int argc, char* argv[]){
    vector<char> tape;
    Container* cont = new Container();
    char *iftrans=new char();
    char *state=new char();
    int *nodeNum=new int();
    char *before= new char();
    int *transNode=new int();
    char *after=new char();
    char *point=new char();
    string filename;
    //read in file
    if(argc==4){
        filename= argv[1];
    }else{
        cout<<"Please enter the correct number of command line arguments\n";
        return 1;
    }
                   
    ifstream input;
    input.open(filename);
    
    //check that file opened properly
    if(!input.is_open()){
        cout<<"No such file\n";
        return 1;
    }
    //while there are still lines to read
    while(input){
        if(input.eof()){
            input.close();
            break;
        }
        getinp(&input,iftrans,state,nodeNum,before,transNode,after,point);
        //if new node
        if(*iftrans=='s'){
            cont->newNode(*state,*nodeNum);
        }
        //if transition
        if(*iftrans=='t'){
            if(cont->get(*nodeNum)==nullptr){
    		Container::Node *x =cont->newNode(*state,*nodeNum);
		Container::Node *y;
		if(cont->get(*transNode)==nullptr){
			y=cont->newNode('n',*transNode);
                }else{
			y=cont->get(*transNode);
		}
		x-> addTransition(*before,y,*after,*point);
            }else{ 
	       Container::Node* x = cont->get(*nodeNum);    
               Container::Node* y;
	       if(cont->get(*transNode)==nullptr){
			y=cont->newNode('n',*transNode);
	       }else{
		        y=cont->get(*transNode);
	       }
	       x-> addTransition(*before,y,*after,*point);
            }
        }
    }
    input.close();
    string retVal = execute(argv[2],tape,cont,atoi(argv[3]));
    cout<<retVal<<endl;
    
    return 0;
}
