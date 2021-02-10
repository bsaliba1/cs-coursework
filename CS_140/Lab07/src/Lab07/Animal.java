package Lab07;

public abstract class Animal implements Actions, Classifications {
	@Override 
	public String toString(){
		String retVal = "This is the higher " +
				"level abstract animal class. It's " +
				"subclass will implement the interfaces.\n";
		return retVal;
	}
	abstract String getAnimalName();
}
