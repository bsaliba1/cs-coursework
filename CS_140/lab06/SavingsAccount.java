package lab06;

public class SavingsAccount extends BankAccount {
	private double rate;
	
	public SavingsAccount(double balance, double aRate){
		super(balance);
		rate = aRate;
	}
	@Override
	public void deposit(double amount){
		double total = amount*rate;
		double depAmount = total - amount;
		super.deposit(depAmount);
	}
	public double getRate(){
		return rate;
	}
	public String toString(){
		String retString = super.toString();
		retString = retString + "@ " + rate + "%";
		return retString;
	}
}
