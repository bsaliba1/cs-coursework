package lab02;
public class Book {
	private String title;
	private int numPages;
	
	public Book (String aTitle, int aNumPages){
		this.title = aTitle;
		this.numPages = aNumPages;
	}
	public String getTitle(){
		return title;
	}
	public int getNumPages(){
		return numPages;
	}

	
}
