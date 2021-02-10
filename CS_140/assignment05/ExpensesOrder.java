package assignment05;
import java.util.Comparator;

public class ExpensesOrder implements Comparator<TravelExpenses> {
	public int compare(TravelExpenses arg0, TravelExpenses arg1){
		if(arg1 instanceof Meal && arg0 instanceof Meal) {
			int retVal = ((Meal)arg0).getMealType().compareTo(((Meal)arg1).getMealType());
			return retVal;
		}else {
			return (arg0.sequenceNo()-arg1.sequenceNo());
		}
	}
}
