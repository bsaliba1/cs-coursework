package Lab07;

public class Tiger extends Carnivore {
	private String name;
	
	public String getName(){
		return name;
	}
	public Tiger( String prey, int predatoryLevel,String name){
		super(prey,predatoryLevel);
		this.name = name;
	}
	@Override
	public String toString(){
		String retVal = "Tigers are large striped carnivores" +
				"from Asia.";
		return retVal;
	}
	@Override
	public String getAnimalName(){
		return "Tiger";
	}
	public void speak(){
		System.out.println("Growl!");
	}
	@Override
	void prowl() {
		System.out.println("The tiger pounces on an unsuspecting" +
				getPrey());
		
	}
	public void eat() {
		System.out.println(getName()+ "the Tiger eats "+ getPrey());
		
	}
	public void move() {
		System.out.println("Tigers move gracefully due to their powerful" +
				"leg and shoulder muscles");
	}
	public void sleep() {
		System.out.println("Tigers like to sleep in rocky places," +
				" grassy areas, or inside caves");
		
	}
	public String kingdom() {
		
		return "Animalia";
	}
	public String genus() {
		
		return "Panthera";
	}
	public String species() {
		
		return "P.tigris (tiger)";
	}
	
}
