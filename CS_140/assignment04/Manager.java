package assignment04;
import java.lang.StringBuilder;
import java.util.ArrayList;

public class Manager extends Employee{
	private String department;
	private ArrayList<Employee> team = new ArrayList<Employee>();

	public Manager(Person p){
		super(p);
	}
	public void setDepartment(String dep){
		this.department = dep;
	}
	public void addToTeam(Employee p){
		team.add(p);
	}
	public String toString(){
		StringBuilder build = new StringBuilder();
		String s = super.toString();
		build.append(s);
		build.append("Department: ");
		build.append(department);
		return build.toString();
	}
	public void teamToString(){
		String str = "";
		for(int i = 0; i<team.size();i++){
			str = str + team.get(i).toString();
		}
		System.out.println(str);
	}
}