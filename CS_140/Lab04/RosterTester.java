package Lab04;

import java.util.ArrayList;
import java.util.Arrays;

public class RosterTester{
	public static void main (String[] args){
		Roster ros1 = new Roster();
		Student stu1 = new Student();
		stu1.setName("Baptiste Saliba");
		stu1.setId(00003);
		ros1.addStudent(stu1);
		Student stu2 = new Student();
		stu2.setName("Chuck Norris");
		stu2.setId(00002);
		ros1.addStudent(stu2);
		Student stu3 = new Student();
		stu3.setName("Rob Stark");
		stu3.setId(00001);
		ros1.addStudent(stu3);
		System.out.println(ros1.toString());
		ros1.dropStudent("Baptiste Saliba");
		System.out.println(ros1.toString());
		ros1.sortById();
		System.out.println(ros1.toString());

		//Print Student names with Ids
		String myString = "";
		ArrayList<Student> roster = ros1.getRoster();
		for (int i=0; i<ros1.getRoster().size();i++){
			Student x = roster.get(i);
			myString = myString+"Name: "+x.getName()+" ID: "+x.getId()+" | ";
		}
		System.out.println(myString);
	}
}