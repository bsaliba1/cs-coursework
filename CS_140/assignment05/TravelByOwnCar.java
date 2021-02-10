package assignment05;
import java.time.LocalDate;

public class TravelByOwnCar implements TravelExpenses{
	private double milesDriven;
	private LocalDate startDate;
	private LocalDate endDate;
	
	public TravelByOwnCar(LocalDate aStartDate,
						LocalDate aEndDate) {
		this.startDate = aStartDate;
		this.endDate = aEndDate;
	}
	public void addMiles(double numMiles) {
		milesDriven = milesDriven + numMiles;
	}
	@Override 
	public String getDescription() {
		String retVal = "Own car used, miles driven: "+milesDriven;
		return retVal;
	}
	@Override
	public double amountToReimburse() {
		double retVal = milesDriven *mileage;
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
		return 5;
	}
}
