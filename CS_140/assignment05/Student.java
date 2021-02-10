package assignment05;

import java.util.Comparator;

public class Student {
	private Person self;
	private Course course = null;
	private int[] progress;
	private boolean[] completed;
	
	public Student(Person aSelf) {
		this.self= aSelf; 
	}
	public void setCourse(Course crs) {
		this.course = crs;
		progress = new int[crs.getNumReadings()];
		completed = new boolean[course.getNumReadings()];
	}
	public void read(int reading) {
		if(completed[reading]!=true) {
			if(progress[reading]!= course.getTotalPages(reading)) {
				progress[reading]++;
			}
			if(progress[reading]== course.getTotalPages(reading)) {
				completed[reading] = true;
			}
		}else {
			System.out.println("Reading already completed");
		}
	}
	public int percentRead() {
		int totalPagesRead = 0;
		for(int i = 0 ; i<completed.length;i++) {
			if(completed[i]==true) {
				totalPagesRead = totalPagesRead+course.getTotalPages(i);
			}else {
				totalPagesRead = totalPagesRead + progress[i];
				break;
			}
		}
		double percent = totalPagesRead/course.getAllPages();
		int retVal = (int)Math.round(percent);
		return retVal;
	}
	public int percentCompleted() {
		int numReadingsCompleted = 0;
		for(int i = 0 ; i<completed.length;i++) {
			if(completed[i]==true) {
				numReadingsCompleted++;
			}
		}
		double percent = numReadingsCompleted/course.getNumReadings();
		int retVal = (int)Math.round(percent);
		return retVal;
	}
	public Course getCourse() {
		return course;
	}
	public Person getSelf() {
		return self;
	}
	public int compareTo(Student other) {
		 if (course==null && other.getCourse()!=null) {
			 return -1;
		 }
		 if (course!=null && other.getCourse()==null) {
			 return 1;
		 }
		 if (course==null && other.getCourse()==null) {
			 if(percentRead()>other.percentRead()){
				 return 1;
			 }
			 if(percentRead()<other.percentRead()){
				 return -1;
			 }else {
				 if(percentCompleted()>other.percentCompleted()){
					 return 1;
				 }
				 if(percentCompleted()<other.percentCompleted()){
					 return -1;
				 }else {
					 return self.compareTo(other.getSelf());
				 }
			 }
		}else {
			return 0;
		}
	}
}