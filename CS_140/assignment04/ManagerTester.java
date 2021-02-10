package assignment04;

public class ManagerTester{
	public static void main(String[] args){
		Person a1 = new Person("Christian", "Bale",'B');
		Manager cB = new Manager(a1);
		cB.setDepartment("IT");
		System.out.println(cB.toString());

		Person a2 = new Person("Bob", "Hough", 'L');
		Employee bH = new Employee(a2);
		cB.addToTeam(bH);

		Person a3 = new Person("Hank","Schrader",'B');
		Employee hS = new Employee(a3);
		cB.addToTeam(hS);
		cB.teamToString();

		Person b1 = new Person("Baptiste", "Saliba", 'E');
		Manager bS = new Manager(b1);
		bS.setDepartment("Astrophysics");
		System.out.println(bS.toString());

		Person b2 = new Person("Team2a","Team2b",'c');
		Employee ab = new Employee(b2);
		bS.addToTeam(ab);

		Person b3 = new Person("Team2c","Team2d",'e');
		Employee cd = new Employee(b3);
		bS.addToTeam(cd);

		Person b4 = new Person("Team2e","Team2f",'g');
		Employee ef = new Employee(b4);
		bS.addToTeam(ef);
		bS.teamToString();

	}
}