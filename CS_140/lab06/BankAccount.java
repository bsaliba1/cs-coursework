package lab06;

public class BankAccount {
	private double balance;
	private int idNum;
	private static int numAccounts = 0;
	
	public BankAccount(double aBalance){
		if(!(aBalance<0)){
			this.balance = aBalance;
		}else{
			throw new IllegalArgumentException("Input can't be negative");
		}
		idNum = numAccounts;
		numAccounts ++;
	}
	public double getBalance(){
		return balance;
	}
	public int getIdNumber(){
		return idNum;
	}
	static void reset(){
		numAccounts = 0;
	}
	@Override
	public String toString(){
		String retVal = "";
		retVal = retVal + "Acct. #"+idNum+ "has $"+balance; 
		return retVal;
	}
	public void deposit(double amount){
		balance = balance +amount;
	}
	public double withdraw(double amount){
		double retVal = 0.0;
		if(!(amount>balance)){
			balance = balance-amount;
			retVal = amount;
		}else{
			retVal = balance;
			balance = 0;
		}
		return retVal;
	}
}
