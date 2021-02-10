package assignment06;
import java.util.Iterator;
import java.util.Stack;

public class CompositeIterator implements Iterator<MComp> {
	private Stack<Iterator<MComp>> stack = new Stack<>();
	
	public CompositeIterator(Iterator<MComp> iterator) {
		stack.push(iterator);
	}
	public boolean hasNext() {
		if (stack.empty()){
		return false;
		}
		//exam the top iterator in the stack
		Iterator<MComp> iterator = stack.peek();
		if (!iterator.hasNext()) {
			stack.pop();
			return hasNext();
		}else{
			return true;
		}
	}
	public void remove() {
		throw new UnsupportedOperationException();
	}
	public MComp next() {
		if (!hasNext()) {
			return null;
		}
		Iterator <MComp> iterator = stack.peek();
		MComp comp = iterator.next();
		if (comp instanceof Menu) {
			stack.push(comp.iterator());
		}
		return comp;
	}
}
