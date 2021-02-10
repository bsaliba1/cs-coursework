package assignment05;
import java.util.ArrayList;
import java.util.Collections;
import java.time.LocalDate;
import java.util.Comparator;

public interface TravelExpenses {
	double mileage = 0.53;
	static double BREAKFAST_MAX = 8.0;
	static double LUNCH_MAX = 10.0;
	static double DINNER_MAX = 40.0;
	
	public double amountToReimburse();
	
	default String getDescription() {
	throw new UnsupportedOperationException("Must be implemented in class");
	}
	
	static void printReport(ArrayList<TravelExpenses> list) {
		Collections.sort(list, Comparator.comparing(TravelExpenses::getStartDate).thenComparing(new ExpensesOrder()));
		double sum = 0;
		for(int i=0; i<list.size();i++) {
			TravelExpenses te = list.get(i);
			String s = String.format("$%.2f", te.amountToReimburse());
			System.out.println(te.getDescription()+s);
			sum = sum + te.amountToReimburse();
		}
		System.out.println("Total Expense:"+ sum);
	}
	default LocalDate getStartDate() {
		return LocalDate.now();
	}
	default LocalDate getEndDate() {
		return LocalDate.now();
	}
	default int sequenceNo() {
		return Integer.MAX_VALUE;
	}
	
}
