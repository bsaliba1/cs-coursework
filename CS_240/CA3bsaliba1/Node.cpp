Node::Node(){
	
}
Node::Node(string str){
	data =str;
}
Node::Node(Node* node){
	data=node->data;
}
