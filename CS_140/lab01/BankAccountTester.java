package lab01;
public class BankAccountTester {
	public static void main(String[] args) {
		BankAccount harrysChecking = new BankAccount();
		harrysChecking.deposit(2000.0);
		harrysChecking.withdraw(500.0);
		System.out.println(harrysChecking.getBalance());
		System.out.println("Expected: 1500.0");
	}
}

