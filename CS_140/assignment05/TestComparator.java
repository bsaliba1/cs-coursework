package assignment05;
import java.time.LocalDate;
import java.util.ArrayList;

public class TestComparator {
	public static void main(String[] args) {
		Meal meal1 = new Meal(MealType.LUNCH, 12.50,LocalDate.now());
		Meal meal2 = new Meal(MealType.BREAKFAST,24.00, LocalDate.of(2017,04,04));
		Lodging lodge1 = new Lodging(LocalDate.of(2017, 05, 16),LocalDate.of(2017, 06, 18),
						"Hilton",200.00);
		Lodging lodge2 = new Lodging(LocalDate.of(2017, 07, 13),LocalDate.of(2017, 07, 21),
						"Holiday Inn",350.00);
		TravelByOwnCar car1 = new TravelByOwnCar(LocalDate.of(2017, 05, 13),LocalDate.of(2017, 07, 21));
		car1.addMiles(65.00);
		System.out.println(meal1.getMealType());
		System.out.println(meal1.getStartDate());
		System.out.println(meal2.getMealType());
		System.out.println(meal2.getStartDate());
		System.out.println(lodge1.getStartDate());
		System.out.println(lodge1.sequenceNo());
		System.out.println(lodge1.amountToReimburse());
		ArrayList<TravelExpenses> array = new ArrayList<TravelExpenses>();
		array.add(meal1);
		array.add(meal2);
		array.add(lodge1);
		array.add(lodge2);
		array.add(car1);
		
		TravelExpenses.printReport(array);
	}
}
