package assignment05;

import java.util.Collections;
import java.util.Comparator;
import java.util.ArrayList;

public class Test2 {
	public static void main(String[] args) {
	
	Person person1 = new Person("Carol",NamesResource.getRandomFirstName(),NamesResource.getRandomBirthDate(2013));
	Person person2 = new Person("Bens",NamesResource.getRandomFirstName(),NamesResource.getRandomBirthDate(2013));
	Person person3 = new Person("Adams",NamesResource.getRandomFirstName(),NamesResource.getRandomBirthDate(2013));
	
	Student student1 = new Student(person1);
	Student student2 = new Student(person2);
	Student student3 = new Student(person3);
	
	Course course1 = new Course("WTSN");
	Course course2 = new Course("ENVI");
	Course course3 = new Course("HMN");
	
	course1.setNumReadings(6);
	course2.setNumReadings(2);
	course3.setNumReadings(1);
	
	course1.setPages(6,50);
	course1.setPages(5,45);
	course1.setPages(4,40);
	course1.setPages(3,35);
	course1.setPages(2,30);
	course1.setPages(1,25);

	course2.setPages(2,30);
	course2.setPages(1,25);
	
	course3.setPages(1,25);
	
	student1.setCourse(course1);
	student2.setCourse(course2);
	student3.setCourse(course3);
	
	ArrayList<Student> list = new ArrayList<Student>();
	list.add(student1);
	list.add(student2);
	list.add(student3);
	Collections.sort(list, new Comparator<Student>() {
		@Override
		public int compare(Student student1, Student student2) {
			return student1.compareTo(student2);
		}
	});
	System.out.println("Expected-------"+"\n"+"Carol"+"\n"+ "Bens"+"\n"+ "Adams");
	System.out.println("Output-------");
	for(Student x:list) {
		System.out.println(x.getSelf().getLastName());	
	}
	}
}
