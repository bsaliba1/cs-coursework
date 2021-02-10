#include <string>

using namespace std;

class Edge{
	public:
	string src;
	string destination;
	Time d_time;
	Time a_time;
	int price;

	Edge(const string s, const string d, const Time dt,const Time at,const int p){
		src = s;
		destination = d;
		d_time = dt;
		a_time = at;
		price = p;
	}
	friend ostream& operator<<(ostream&os, const Edge& t){
		os<<t.src<<" "<<t.destination<<" "<<t.d_time<<" "<<
			t.a_time<<" $"<<t.price;
		return os;
	}
};
