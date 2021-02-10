package assignment03;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class CalenderItem{
	private LocalDateTime start;
	private LocalDateTime end;
	private String title;
	private String description;
	private String location;
	private CalenderItem nextItem;


	public LocalDateTime getStart(){
		return start;
	}
	public void setStart(LocalDateTime aStart){
		/*if(end != null && end.isBefore(end)){
		throw new IllegalArgumentException("the start cannot be after end");
		}else{*/
			start = aStart;
		//}
	}
	public LocalDateTime getEnd(){
		return end;
	}
	public void setEnd(LocalDateTime aEnd){
		/*if(start != null && start.isAfter(end)){
		throw new IllegalArgumentException("the start cannot be after end");
		}else{*/
			end = aEnd;
		//}

	}
	public String getTitle(){
		return title;
	}
	public void setTitle(String aTitle){
		title = aTitle;
	}
	public String getDescription(){
		return description;
	}
	public void setDescription(String aDescription){
		description = aDescription;
	}
	public String getLocation(){
		return title;
	}
	public void setLocation(String aLocation){
		location = aLocation;
	}
	public CalenderItem getNextItem(){
		return nextItem;
	}
	public void setNextItem(CalenderItem aNextItem){
		nextItem = aNextItem;
	}
	public String toString() {
		DateTimeFormatter dayForm =  DateTimeFormatter.ofPattern("MMMM d, yyyy");
		DateTimeFormatter timeForm =  DateTimeFormatter.ofPattern("h:m a");
		return start.format(dayForm) +" from " + start.format(timeForm) 
				+ " to " + end.format(timeForm) + "\n"
				+ title + " in " + location + "\n"
				+ description;
	}
	public boolean endsBefore(CalenderItem other){
		return end.isBefore(other.start);
	}
	public boolean startsAfter(CalenderItem other){
		return start.isAfter(other.end);
	}
	public boolean noTimeConflictWith(CalenderItem other) {
		return endsBefore(other) || startsAfter(other);
	}	
	public boolean hasTimeConflictWith(CalenderItem other) {
		return !noTimeConflictWith(other);
	}
	public boolean isEqual(CalenderItem other){
		boolean x = false;
		if (start.isEqual(other.start)){
			x= true;
		}
		return x;
	}

	public static void main(String[] args) {
	CalenderItem test = new CalenderItem();
	test.setDescription("this is just a sample meeting of CS 140");
	test.setEnd(LocalDateTime.of(2017,9,11,11,50));
	test.setStart(LocalDateTime.of(2017,9,11,10,50));
	test.setTitle("CS 140");
	test.setLocation("FA 212");
	
	System.out.println(test);

	CalenderItem other = new CalenderItem();
	other.setDescription("this is just a sample meeting of CS 140B");
	other.setEnd(LocalDateTime.of(2017,9,12,16,00));
	other.setStart(LocalDateTime.of(2017,9,12,10,30));
	other.setTitle("CS 140");
	other.setLocation("FA 212");

	System.out.println(other);
	System.out.println(test.noTimeConflictWith(other));
	
	}
}