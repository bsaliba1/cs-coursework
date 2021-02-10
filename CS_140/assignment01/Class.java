package assignment01;

public class Class {
	private String name;
	private String number;
	private int crn;
	private	int numCredits;
	private double qualPoints; 
	//Constructor
	public Class (String aName, String aNumber, 
				  int aCrn,int aNumCredits){
		this.name = aName;
		this.number = aNumber;
		this.crn = aCrn;
		this.numCredits= aNumCredits;
	}
	//Create a Dummy Class
	public static final Class DUMMY_CLASS = new Class ("Dummy","000",0,0);

	//Getter methods
	public String getName(){
		return name;
	}
	public String getNumber(){
		return number;
	}
	public int getCrn(){
		return crn;
	}
	public int getNumCredits(){
		return numCredits;
	}
	public double getQualPoints(){
		return qualPoints;
	}

	//Setter method for qualPoints
	public void setQualPoints(double qPoints){
		qualPoints = qPoints*getNumCredits();
	}

}