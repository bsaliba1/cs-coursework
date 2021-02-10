package assignment05;
import java.time.LocalDate;

public class TravelByRail implements TravelExpenses {
	private LocalDate outboundStartDate;
	private LocalDate inboundEndDate;
	private String railLines;
	private double totalCost;
	
	public TravelByRail(LocalDate aOutboundStartDate,
			LocalDate aInboundEndDate, 
			String aRailLines,
			double aTotalCost) {
		this.outboundStartDate = aOutboundStartDate;
		this.inboundEndDate = aInboundEndDate;
		this.railLines = aRailLines;
		this.totalCost = aTotalCost;
		}
	
	@Override
	public double amountToReimburse() {
		return totalCost;
	}
	@Override
	public String getDescription() {
		String retVal = "The raillines used were/are : "+railLines;
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
		return 2;
	}
}
