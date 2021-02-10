package assignment06;
import java.util.ArrayList;
import java.util.Iterator;

public class Menu implements MComp{
	private String name;
	private String description;
	ArrayList<MComp> comps = new ArrayList<MComp>();
	
	public Menu(String aName, String aDescription) {
		this.name = aName;
		this.description = aDescription;
	}
	@Override
	public Iterator<MComp> iterator() {
		return new CompositeIterator(comps.iterator());
	}
	@Override
	public void add(MComp mComp) {
		comps.add(mComp);
	}
	@Override
	public void remove(MComp mComp) {
		comps.remove(mComp);
	}
	@Override
	public MComp getChild(int i) {
		return comps.get(i);
	}
	@Override
	public String getName() {
		return name;
	}
	@Override
	public String getDescription() {
		return description;
	}
	@Override
	public void print() {
		System.out.println("\n"+getName());
		System.out.println(", "+getDescription());
		System.out.println("----------------------");
		Iterator<MComp>iter = comps.iterator();
		while(iter.hasNext()) {
			iter.next().print();
		}
	}
	public MComp get(int index) {
		return comps.get(index);
	}
}
