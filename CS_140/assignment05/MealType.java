package assignment05;

public enum MealType {
	BREAKFAST(TravelExpenses.BREAKFAST_MAX), 
	LUNCH(TravelExpenses.LUNCH_MAX), 
	DINNER(TravelExpenses.DINNER_MAX);
	
	private double max;
	private MealType(double max) {
		this.max = max;
	}
	
	public double getMax() {
		return max;
	}
}
