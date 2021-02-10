package Lab07;

public class Deer extends Herbivore {
	private String name;
	public Deer(String foliage, int agressionLevel, String name){
		super(foliage, agressionLevel);
		this.name = name;
	}
	public String getName(){
		return name;
	}
	@Override
	public String getAnimalName(){
		return "Deer";
	}
	@Override
	public String toString(){
		return "Here in New York, Deer are known for jumping out in front of cars and causing costly accidents.";
	}
	public void speak() {
		System.out.println("Deer make a little whiney noise, almost like a kazoo.");
	}
	public void eat() {
		System.out.println(name + " the Deer likes to eat an " + super.getFoliage());	
	}
	public void move() {
		System.out.println("Deer are light on their feet and gallop through grasslands and wooded areas.");
	}
	public void sleep() {
		System.out.println("Deer sleep in direct sunlight to stay warm, and are often more active at night than daytime.");
	}
	public String kingdom() {
		return "Animalia";
	}
	public String genus() {
		return "Hydropotes";
	}
	public String species() {
		return "H.inermis (water deer)";
	}
	@Override
	void graze() {
		System.out.println("The deer spots a fallen " + super.getFoliage() + " underneath the nearby tree" );
	}

}
