package assignment05;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;


public class Lodging implements TravelExpenses {
	private LocalDate startDate;
	private LocalDate endDate;
	private String lodgingName;
	private int numberOfNights;
	private double costOfStay;
	
	public Lodging(LocalDate aStartDate, LocalDate aEndDate,
					String aLodgingName, double aCostOfStay) {
		this.startDate = aStartDate;
		this.endDate = aEndDate;
		this.lodgingName = aLodgingName;
		this.costOfStay = aCostOfStay;
		this.numberOfNights = (int)ChronoUnit.DAYS.between(startDate, endDate);

	}
	
	@Override
	public double amountToReimburse() {
		return costOfStay;
	}
	@Override
	public String getDescription() {
		String retVal = "Stayed at "+lodgingName+". Cost of stay is "+ costOfStay+". The stay is from "
				+startDate+" to "+endDate+" which is "+numberOfNights+".";
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

}
