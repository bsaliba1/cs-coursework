package Lab07;

public abstract class Herbivore extends Animal {
	private String foliage;
	private int agressionLevel;
	
	abstract void graze();
	
	public Herbivore(String aFoliage, int aAgressionLevel){
		this.foliage = aFoliage;
		this.agressionLevel = aAgressionLevel;
	}
	@Override
	public String toString(){
		String retVal = "A herbivore only eats plants." +
				"It can additionally perform the action graze," +
				"and has foliage it eats.";
		return retVal;
	}
	public String getFoliage(){
		return foliage;
	}
	public int getAgressionLevel(){
		return agressionLevel;
	}
}
