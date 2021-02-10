
using namespace std;

class Graph{
	public:
	int city_num=0;
	map<string,int> city_map;
	vector<Node*> cities;
	
	Graph(){
	
	}
	void addEdge(Edge *x){
		int c;
		int t;
		if(city_map.find(x->src)==city_map.end()){
			city_map[x->src]=city_num;
			c=city_num;
			Node* n = new Node(x->src);
			n->num=city_num;
			cities.push_back(n);
			city_num++;
		}else{
			c = city_map[x->src];
		}
		if(city_map.find(x->destination)==city_map.end()){
			city_map[x->destination]=city_num;
			t=city_num;
			Node* n = new Node(x->destination);
			n->num=city_num;
			cities.push_back(n);
			city_num++;
		}else{
			t = city_map[x->destination];
		}
		cities[c]->trans.push_back(x);
		cities[c]->adj.push_back(cities[city_map[x->destination]]);
	}
	vector<string> BFS(string from, string to){
		int x = city_map[from];
		int y = city_map[to];
		Node *first = cities[x];

		for(int i=0; i<cities.size();i++){
			cities[i]->color=0;
			cities[i]->dist=0;
			cities[i]->pre=NULL;
		}
		first->color=1;
		first->dist=0;
		first->pre=NULL;

		list<Node*> q;
		Node* last=NULL;
		q.push_back(first);
		while(q.size()!=0){
			Node* curr = q.front();
			q.pop_front();
			for(Node* w:curr->adj){
				if(w->color==0){
					w->color=1;
					w->dist=curr->dist+1;
					w->pre=curr;
					q.push_back(w);	
				}
			}
			if(curr->city==to){
				last = curr;
			}
			curr->color=2;
		}
		vector<string> retVal;	
		int z = last->dist+1;
		for(int i=0;i<z;i++){
			retVal.insert(retVal.begin(),last->city);
			last = last->pre;
			
		}
		return retVal;
		
	}
	void anyItinerary(string from, string to){
		vector<string> going = BFS(from, to);
		vector<string> back = BFS(to, from);
		for(int i=0;i<going.size();i++){
			if(i!=going.size()-1){
				cout<<going[i]<<" -> ";
			}else{
				cout<<going[i];
			}
		}
		for(int i=1;i<back.size();i++){
			if(i!=back.size()-1){
				cout<<" -> "<<back[i];
			}else{
				cout<<" -> "<<back[i]<<endl;
			}
		}
	}
	vector<Edge*> Dijstra (string from, string to, Time* min){
		int x1 = city_map[from];
		int y1 = city_map[to];
		Node *first = cities[x1];

		for(int i=0; i<cities.size();i++){
			cities[i]->time=new Time("11:59pm");
			cities[i]->pre=NULL;
		}
		first->time = min;
		first->pre=NULL;

       	vector<string> Q;
		for(Node* ab:cities){
			Q.push_back(ab->city);
		}
		Node* last;
		int counter=0;
		while(Q.size()!=0){
			/*for(string as:Q){
				cout<<as<<" ";
			}
			cout<<endl;*/
			string temp = extractMin(Q);
			int x = city_map[temp];//use Q
			Node* u = cities[x];//use Q
			for(int it=0;it<Q.size();it++){
				if(Q[it]==temp){
					Q.erase(Q.begin()+it);
				}
			}
			u->relax(min,cities,city_map);	
			if(u->city == to){
				last = u;
			}
		}
		vector<Edge*> retVal;
		while(last->pre!=NULL){
			retVal.insert(retVal.begin(),last->min_edge);
			last = last->pre;	
		}
		return retVal;
	}	
	void earliestArrival(string from, string to, Time* x, Time* y){
		vector<Edge*> going = Dijstra(from, to, x);
		vector<Edge*> back = Dijstra(to, from, y);
		//cout<<"going size: "<<going.size()<<endl;
		for(int i=0;i<going.size();i++){
			if(i!=going.size()-1){
				cout<<*going[i]<<" -> ";
			}else{
				cout<<*going[i];
			}
		}
		for(int i=0;i<back.size();i++){
			if(i!=back.size()-1){
				cout<<" -> "<<*back[i];
			}else{
				cout<<" -> "<<*back[i]<<endl;
			}
		}
		//cout<<"back size: "<<back.size()<<endl;

	}
	string extractMin(vector<string> x){
		Time temp = Time("11:59pm");
		string retNode = x[0];
		for(string it:x){
			Node* c = cities[city_map[it]];
			if(c->time<temp){
				temp = c->time;
				retNode = c->city;
			}
		}
		return retNode;
	}	
};	
