package assignment05;
import java.time.LocalDate;

public class TravelByBus implements TravelExpenses{
	private LocalDate outboundStartDate;
	private LocalDate inboundEndDate;
	private String busLine;
	private double totalCost;
	
	public TravelByBus(LocalDate aOutboundStartDate,
			LocalDate aInboundEndDate, 
			String aRailLines,
			double aTotalCost) {
		this.outboundStartDate = aOutboundStartDate;
		this.inboundEndDate = aInboundEndDate;
		this.busLine = aRailLines;
		this.totalCost = aTotalCost;
		}
	
	@Override
	public double amountToReimburse() {
		return totalCost;
	}
	@Override
	public String getDescription() {
		String retVal = "The buslines used were/are : "+busLine;
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
		return 3;
	}
}
