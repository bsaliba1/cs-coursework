package assignment05;

public class Course {
	private String courseName;
	private int[] pagesToRead;
	
	public Course(String aCourseName) {
		this.courseName = aCourseName;
	}
	public void setNumReadings(int readings) {
		this.pagesToRead = new int[readings];
	}
	public void setPages(int reading,int totalPages) {
		pagesToRead[reading-1] = totalPages;
	}
	public int getNumReadings() {
		return pagesToRead.length;
	}
	public int getTotalPages(int reading) {
		return pagesToRead[reading];
	}
	public int getAllPages() {
		int totPages= 0;
		for(int x:pagesToRead) {
			totPages= totPages+ getTotalPages(x);
		}
		return totPages;
	}
	public String getCourseName() {
		return courseName;
	}
}
