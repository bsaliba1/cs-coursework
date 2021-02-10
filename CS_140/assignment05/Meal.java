package assignment05;

import java.time.LocalDate;

public class Meal implements TravelExpenses {
	private MealType mealType;
	private double amountPaid;
	private LocalDate date;
	
	public Meal(MealType meal, double amount, LocalDate aDate) {
		this.mealType = meal;
		this.amountPaid = amount;
		this.date = aDate;
	}

	@Override
	public double amountToReimburse() {
		double retVal = Math.max(amountPaid, mealType.getMax());
		return retVal;
	}
	@Override
	public String getDescription() {
		String retVal = mealType+" on "+ date + ".";
		return retVal;
	}
	@Override
	public LocalDate getStartDate() {
		return date;
	}
	@Override 
	public LocalDate getEndDate() {
		return date;
	}
	public MealType getMealType() {
		return mealType;
	}
}
