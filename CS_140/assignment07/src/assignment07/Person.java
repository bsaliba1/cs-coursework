package assignment07;

import java.time.LocalDate;
import java.util.Comparator;

public class Person implements Comparable<Person>{
	private String lastName;
	private String firstNames;
	private LocalDate dateOfBirth;
	
	
	public Person(String lastName, String firstNames, LocalDate dateOfBirth) {
		super();
		this.lastName = lastName;
		this.firstNames = firstNames;
		this.dateOfBirth = dateOfBirth;
	}
	public String toString() {
		return lastName + ", " + firstNames + " (" + dateOfBirth + ")";			
	}
	@Override
	public int compareTo(Person arg0) {
		return (lastName + firstNames).compareToIgnoreCase(arg0.lastName + arg0.firstNames);
	}
	
	public LocalDate getDateOfBirth() {
		return dateOfBirth;
	}
	
	public static Comparator<Person> byDOB () {
		return Comparator.comparing(Person::getDateOfBirth);
	}
	
	public static Comparator<Person> byDOBandName () {
		return byDOB().thenComparing(Comparator.naturalOrder());
	}
}
