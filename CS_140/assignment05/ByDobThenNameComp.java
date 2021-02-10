package assignment05;

public class ByDobThenNameComp {
	public int compare(Person person1,Person person2) {
		int retVal = person1.getDob().compareTo(person2.getDob());
		if(retVal!= 0) {
			return retVal;
		}else {
			retVal = person1.compareTo(person2);
			return retVal;
		}
	}
}
