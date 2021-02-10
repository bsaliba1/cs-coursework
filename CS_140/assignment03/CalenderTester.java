package assignment03;
import java.time.LocalDateTime;
import java.util.Optional;

public class CalenderTester{
	public static void main(String[] args){
		CalenderItem test = new CalenderItem();
		test.setEnd(LocalDateTime.of(2017,10,21,11,50));
		test.setStart(LocalDateTime.of(2017,10,21,10,50));

		CalenderItem other = new CalenderItem();
		other.setEnd(LocalDateTime.of(2017,10,30,16,11));
		other.setStart(LocalDateTime.of(2017,10,30,13,30));

		CalenderItem other1 = new CalenderItem();
		other1.setEnd(LocalDateTime.of(2017,10,31,16,11));
		other1.setStart(LocalDateTime.of(2017,10,31,13,30));

		CalenderItem other2 = new CalenderItem();
		other2.setEnd(LocalDateTime.of(2017,11,30,16,11));
		other2.setStart(LocalDateTime.of(2017,11,30,13,30));

		CalenderList calender = new CalenderList();
		calender.printCalender();//works
		System.out.println("NOT SURE WHY IT'S PRINTING THE NULLS. Seems that for some reason when printing the values of each calender item 'null in null' followed by'null' prints"+"\n");
		calender.insertItem(other);
		calender.printCalender();
		System.out.println("\n"+"Demonstates that printCalender works");
		calender.insertItem(test);
		calender.printCalender();
		
		System.out.println("\n"+"Demonstates that printNext works");
		calender.printNext();

		System.out.println("\n"+"Can only hold two appointments");
		calender.insertItem(other1);
		calender.printCalender();
		calender.insertItem(other2);
		calender.printCalender();

		System.out.println("\n"+"Demonstates that findConflict works");
		System.out.println(calender.findConflict(other2));
		System.out.println(calender.findConflict(other1));

		System.out.println("\n"+"Demonstates that resetFirst() works");
		calender.resetFirst();
		calender.printCalender();

	}	
}