#include <string>
using namespace std;

template <typename ElementType>
class LLC{
	private :
		class Node{
			public:	
			ElementType data;
			Node * next;
		
			Node();
			Node(ElementType str);	
			Node(Node* node);
		};
	public:
		Node* first;
		Node* last;
		int numNodes;
	
		LLC();
		LLC(LLC *to_copy);
		Node* insert(const ElementType str);
		~LLC();
		void remove(ElementType val);
		bool contains(ElementType val);
		void shuffle();
		int len();
		ElementType tail();
		LLC<ElementType> operator=(const LLC<ElementType>& list);
		LLC<ElementType> operator+(const LLC<ElementType>& list);
		void head(int n);
		LLC<ElementType>& operator+=(int n);
		void join(const LLC<ElementType>& other);
		template<typename U> friend ostream& operator<<(ostream& os, LLC<U>* list);
};

#include "LLC.cpp"
