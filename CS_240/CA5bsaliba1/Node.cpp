using namespace std;

class Node{
	public:
	string city;
	int num;
	int infinity = 10000000;
	int dist;
	int color; //white =0, grey =1, black =2;
	Time time;
	Node *pre;
	Edge* min_edge;
	vector<Node*>adj;
	vector<Edge*> trans;

	Node(string c){
		city = c;
		dist = infinity;
		color = 0;
		time = Time("11:59pm");
	}	
	void relax(Time* m, vector<Node*> cities, map<string,int> amap){
		for(Node* w:adj){
			for(Edge* e:trans){
				if(w->city==e->destination){
					if(e->d_time>*m){
						if(e->a_time<w->time){
							w->time=e->a_time;
							w->min_edge=e;
							w->pre = this;
						}
		
					}
				}
			}

		}
	}
};
