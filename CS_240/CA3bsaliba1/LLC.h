#include <string>
using namespace std;

class LLC{
	private :
		class Node{
			public:	
			string data;
			Node * next;
		
			Node();
			Node(string str);	
			Node(Node* node);
		};
	public:
		Node* first;
		Node* last;
		int numNodes;
	
		LLC();
		LLC(LLC *to_copy);
		Node* insert(const string str);
		~LLC();
		void remove(string val);
		bool contains(string val);
		void shuffle();
		int len();
		string tail();
		LLC operator=(const LLC& list);
		LLC operator+(const LLC& list);
		void head(int n);
		LLC& operator+=(int n);
		void join(const LLC& other);
		friend ostream& operator<<(ostream& os, LLC* list);
};
