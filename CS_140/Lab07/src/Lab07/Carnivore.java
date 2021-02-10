package Lab07;

public abstract class Carnivore extends Animal{
	private String prey;
	private int predatoryLevel;
	
	abstract void prowl();
	
	public Carnivore(String aPrey, int aPredatoryLevel){
		this.prey = aPrey;
		this.predatoryLevel = aPredatoryLevel;
	}
	@Override
	public String toString(){
		String retVal = "A Carnivore only eats meat." +
				"It can additionally perform the action" +
				"prowl, and has prey it eats.";
		return retVal;
	}
	public String getPrey(){
		return prey;
	}
	public int getPredatoryLevel(){
		return predatoryLevel;
	}
}
