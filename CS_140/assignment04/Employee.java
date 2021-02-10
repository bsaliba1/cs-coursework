package assignment04;
import java.lang.StringBuilder;

public class Employee{
	private Person person;
	private double salary;

	public Employee(Person p){
		this.person = p;
	}
	public void setSalary(double sal){
		salary = sal;
	}
	public String toString(){
		StringBuilder build = new StringBuilder();
		build.append("Name: ");
		build.append(person.getFirstName());
		build.append(" ");
		build.append(person.getLastName());
		build.append(" Salary: ");
		build.append(salary).toString();
		build.append(" ");
		return build.toString();
	}
}