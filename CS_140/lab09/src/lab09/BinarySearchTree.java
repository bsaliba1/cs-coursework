package lab09;

import java.util.Comparator;
import java.util.ArrayList;
import java.util.List;

/**
 * A class to implement the Binary Search Tree data structure.
 * The structure is generic in the type of Objects it contains.
 * @param <T> the type of the contained elements this structure is to hold
 */
public class BinarySearchTree<T> {
    private Comparator<T> comparator;
    private T data;
    private BinarySearchTree<T> left;
    private BinarySearchTree<T> right;
    private  List<T> list = new ArrayList<>();

    /**
     * Constructs an empty BST with a Comparator
     * @param comp the Comparator to use to impose an ordering on instances of T
     */
    public BinarySearchTree(Comparator<T> comp) {
        this.comparator = comp;
    }

    /**
     * Constructs a BST with data and a Comparator
     * @param data the data this BST should hold
     * @param comp the Comparator to use to impose an ordering on instances of T
     */
    public BinarySearchTree(T data, Comparator<T> comp) {
        this.data = data;
        this.comparator = comp;
    }

    /**
     * Inserts an element into this BST
     * @param element the element to insert into this BST
     */
    public void insert(T element) {
        if(data == null) {
    			this.data = element;
    			return;
        }if(comparator.compare(element,data)<=0) {
            if(left==null) {
        			left = new BinarySearchTree(comparator);
            }
			left.insert(element);
        }else{
        		if(right == null) {
        			right = new BinarySearchTree(comparator) ;
        		}
        		right.insert(element);
        }
    }

    /**
     * Searchs for a given element in this BST
     * @param element the element to search this BST for
     * @return the element in this BST matching the given element, if found,
     *         otherwise null if the given element is not in this BST
     */
    public T find(T element) {
        if(comparator.compare(element, data)==0) {
        		return data;
        }if(comparator.compare(element, data)>0) {
        		return right.find(element);
        }else{
        		return left.find(element);
        }
    }

    /**
     * Gathers all the elements of this BST in order
     * @return a List holding the elements in this BST in order
     */
    public List<T> getElements(List<T> aList,List<Integer> level) {  
    		int i =0;
    		getElementHelper(aList, level,i);
    		list.sort(comparator);
        List<T> retVal = list;
        list = null;
        return retVal;
    }
    private void getElementHelper(List<T> aList,List<Integer> level, int i) {
		if(left!= null) {
    			left.getElementHelper(aList, level, i+1);
		}
    		aList.add(data);
		level.add(i);
    		if(right!= null) {
			 right.getElementHelper(aList,level,i+1);
		}
    		System.out.println(level);
    }
    /**
     * Pretty prints the contents of this BST in a horizontal tree-like fashion
     */
    public void prettyPrint() {
        prettyPrint(0);
    }

    private void prettyPrint(int indentLevel) {
	    	List <T> list = new ArrayList<T>();
	    	List<Integer> level = new ArrayList<Integer>();
	    	getElements(list, level);
	    	for(int i = 0; i<level.size();i++) {
	    		for(int k=0; k<level.get(i);k++) {
	    			System.out.print(" ");
	    		}
	    		System.out.print(list.get(i)+"\n");
	    	}
    }
    public T getData() {
    		return data;
    }

    /**
     * A main method supplied for any debugging needs
     */
    public static void main(String[] args) {
        // Up to you how you use this main method, feel free to change it
        Comparator<Integer> intComp = (i, j) -> i - j; // lambda expression
        BinarySearchTree<Integer> tree = new BinarySearchTree<>(intComp);
        tree.insert(3);
        tree.insert(8);
        tree.insert(1);
        tree.insert(0);
        tree.insert(3);
        tree.insert(9);
        tree.insert(4);
        tree.prettyPrint();
    }
}