package assignment03;
import java.time.LocalDateTime;
import java.util.Optional;

public class CalenderList {
	private CalenderItem first;
	private CalenderItem next;

	public void setNext(){
		if(first!=null){
			CalenderItem nowItem = new CalenderItem();
			nowItem.setEnd(LocalDateTime.now());
			nowItem.setStart(LocalDateTime.now());
			CalenderItem temp = first;
			while(temp.endsBefore(nowItem)||temp.isEqual(nowItem)){
				temp = temp.getNextItem();
			}
			next = temp;
		}
	}
	public void resetFirst(){
		setNext();
		first = next;
	}
	public Optional<CalenderItem> findConflict(CalenderItem newItem){
		CalenderItem temp = first;
		if (temp.noTimeConflictWith(newItem)){
			while(temp.getNextItem()!= null){
				temp = temp.getNextItem();
				if (temp.hasTimeConflictWith(newItem)){
					return Optional.of(temp);
				}
			}
			return Optional.empty();

		}else{
			return Optional.empty();

		}
	}
	private void insert(CalenderItem newItem){
		if (first == null){
			first = newItem;
			return;
		}
		if(newItem.endsBefore(first)){
			newItem.setNextItem(first);
			first = newItem;
		}else{
			CalenderItem temp = first;
			while(!newItem.startsAfter(temp.getNextItem()))
				newItem.setNextItem(temp.getNextItem());
				temp.setNextItem(newItem);
		} 
	}
	public void insertItem(CalenderItem newItem){
		if(first!=null){
			setNext();
			CalenderItem nowItem = new CalenderItem();
			nowItem.setEnd(LocalDateTime.now());
			nowItem.setStart(LocalDateTime.now());
			if(newItem.endsBefore(nowItem)){
				throw new IllegalArgumentException("It is too early for that appointment");
			}
			if (nowItem.startsAfter(newItem)){
				throw new IllegalArgumentException("It is too late for that appointment");
			}
			Optional<CalenderItem> temp = findConflict(newItem);
			if(temp.isPresent()) {
				throw new IllegalArgumentException("You have a conflict. "
				+"\n" +"Please use findConflict to find the conflicting appointment");
			}
		}
		insert(newItem);
	}
	public void printNext(){
		System.out.println(next);
	}
	public void printCalender(){
		System.out.println(first);
		if (first!=null){
			CalenderItem temp = first;
			while(temp.getNextItem()!=null){
				temp = temp.getNextItem();
				System.out.println(temp);
			}
		}
	}
}
