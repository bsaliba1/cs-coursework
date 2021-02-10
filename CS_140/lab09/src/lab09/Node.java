package lab09;
import java.util.Comparator;

public class Node implements Comparator<Node>{
	public int value;
	private Node right;
	private Node left;
	
	public Node(int aValue) {
		this.value = aValue;
	}
	public void setRight(Node aRight) {
		this.right = aRight;
	}
	public void setLeft(Node aLeft) {
		this.left = aLeft;
	}
	public Node getRight() {
		return right;
	}
	public Node getLeft() {
		return left;
	}
	@Override
	public int compare(Node o1, Node o2) {
		if (o1.getRight()== o2) {
			return -1;
		}
		if (o1.getLeft() == o2) {
			return 1;
		}
		return 0;
	}
}
