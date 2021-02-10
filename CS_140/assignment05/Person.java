package assignment05;
import java.util.Comparator;
import java.time.LocalDate;

public class Person implements Comparable<Person> {
	private String lastName;
	private String firstNames;
	private LocalDate dob;
	
	public Person(String aLastName,String aFirstName,LocalDate aDob) {
		this.lastName = aLastName;
		this.firstNames = aFirstName;
		this.dob = aDob;
	}
	public int compareTo(Person other) {
		int retVal = (lastName + firstNames).compareToIgnoreCase(other.lastName + other.firstNames);
			return retVal;
	}
	public LocalDate getDob() {
		return dob;
	}
	public String getLastName() {
		return lastName;
	}
	public static Comparator<Person> byDOB () {
		return Comparator.comparing(Person::getDob);
	}
	public static Comparator<Person> byDOBandName () {
		return byDOB().thenComparing(Comparator.naturalOrder());
	}
}
