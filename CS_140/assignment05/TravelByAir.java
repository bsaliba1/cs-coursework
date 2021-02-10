package assignment05;
import java.time.LocalDate;

public class TravelByAir implements TravelExpenses{
	private LocalDate outboundStartDate;
	private LocalDate inboundEndDate;
	private String airlines;
	private double totalCost;
	
	public TravelByAir(LocalDate aOutboundStartDate,
					LocalDate aInboundEndDate, 
					String aAirlines,
					double aTotalCost) {
		this.outboundStartDate = aOutboundStartDate;
		this.inboundEndDate = aInboundEndDate;
		this.airlines = aAirlines;
		this.totalCost = aTotalCost;
	}

	@Override
	public double amountToReimburse() {
		return totalCost;
	}
	@Override 
	public String getDescription() {
		String retVal = "The airline/airlines were"+airlines+
						". The date left was "+outboundStartDate+
						" and the date arrived was "+
						inboundEndDate;
		return retVal;
	}
	@Override
	public LocalDate getStartDate() {
		return outboundStartDate;
	}
	@Override 
	public LocalDate getEndDate() {
		return inboundEndDate;
	}
	@Override
	public int sequenceNo() {
		return 1;
	}
	
}
