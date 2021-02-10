package assignment05;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class TravelByRentalCar implements TravelExpenses {
	
	private double totalRentalCost;
	private double fuelCost;
	private double fuelUsed;
	private int numberOfDaysRented;
	private String rentalCompany;	
	private LocalDate startDate;
	private LocalDate endDate;
	
	public TravelByRentalCar(double aTotalRentalCost, String aRentalCompany, LocalDate aStartDate, LocalDate aEndDate) {
		this.totalRentalCost = aTotalRentalCost;
		numberOfDaysRented = (int)ChronoUnit.DAYS.between(startDate, endDate);
	}
	public void addFuel(double numGallons, double cost) {
		fuelCost= fuelCost+cost;
		fuelUsed = fuelUsed + numGallons;
	}
	@Override 
	public String getDescription() {
		String retVal = "This is a rental car, made by "+ rentalCompany+", rented from "
		+startDate+" to "+endDate+"."+"\n"+"The fuel used was "+Math.round(fuelUsed)+".";
		return retVal;
	}
	@Override
	public double amountToReimburse() {
		double retVal = totalRentalCost+fuelCost;
		return retVal;
	}
	@Override
	public LocalDate getStartDate() {
		return startDate;
	}
	@Override 
	public LocalDate getEndDate() {
		return endDate;
	}
	@Override
	public int sequenceNo() {
		return 4;
	}
}
