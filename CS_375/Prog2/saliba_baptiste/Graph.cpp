typedef struct Node{
	int value;
	int weight;
	float estimate;
	int level;
	std::vector<int> k;

	bool operator<(const Node &rhs) const{
		return (estimate < rhs.estimate);
	}
}Node;

typedef struct Graph{
	Node* start;
}Graph;

