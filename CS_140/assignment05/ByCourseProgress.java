package assignment05;
import java.util.Comparator;

public class ByCourseProgress implements Comparator<Student>{
	public int compare(Student student1, Student student2) {
		return student1.compareTo(student2);
	}
}
