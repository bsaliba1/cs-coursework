package assignment03;

public class Node{
	private int value;
	private Node next;

	public Node(int x){
		value = x;
	}
	public int getValue(){
		return value;
	}
	public Node getNext(){
		return next;
	}
	public void setNext(Node y){
		next = y;
	}

}