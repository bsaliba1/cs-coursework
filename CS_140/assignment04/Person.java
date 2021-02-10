package assignment04;

public class Person {
	private String lastName;
	private String firstName;
	private char middleInitial;
	//Person constructor method
	public Person (String aFirstName,
				   String aLastName,
				   char aMiddleInitial){
		this.lastName = aLastName;
		this.firstName = aFirstName;
		this.middleInitial = aMiddleInitial;

	}
	//Getter method for each of the name fields
	public String getLastName(){
		return lastName;
	}
	public String getFirstName(){
		return firstName;
	}
	public char getMiddleInitial(){
		return middleInitial;
	}

}