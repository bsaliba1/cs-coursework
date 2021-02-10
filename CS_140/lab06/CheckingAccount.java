package lab06;

public class CheckingAccount extends BankAccount{
	private int withdrawLimit;
	private int withdrawCount = 0;
	
	public CheckingAccount(double balance, int limit){
		super(balance);
		withdrawLimit = limit;
	}
	public int getWithdrawLimit(){
		return withdrawLimit;
	}
	public int getWithdrawCount(){
		return withdrawCount;
	}
	@Override
	public String toString(){
		String retString = super.toString();
		retString = retString + " ("+withdrawCount+"/"+withdrawLimit+") ";
		return retString;
	}
	@Override
	public double withdraw(double amount){
		double retVal = 0;
		if(withdrawCount<withdrawLimit){
			retVal = super.withdraw(amount);
			withdrawCount ++;
		}else{
			retVal = 0;
		}
		return retVal;
	}
}
