package assignment06;
import java.util.Iterator;

public class MenuItem implements MComp{
	private String name;
	private String description;
	private boolean vegetarian;
	private double price;
	
	public MenuItem(String aName, String aDescription,
					boolean aVegetarian, double aPrice) {
		this.name = aName;
		this.description = aDescription;
		this.vegetarian = aVegetarian;
		this.price = aPrice;
	}
	public String getName() {
		return name;
	}
	public String getDescription() {
		return description;
	}
	public boolean isVegetarian() {
		return vegetarian;
	}
	public double getPrice() {
		return price;
	}
	@Override
	public Iterator<MComp> iterator() {
		return new NullIterator();
	}
	@Override
	public void print() {
		System.out.print("\t"+getName());
		if(isVegetarian()) {
			System.out.print("(v)");
		}
		System.out.println(", "+getPrice());
		System.out.println("\t\t"+getDescription());
	}
}
