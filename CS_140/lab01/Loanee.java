package lab01;

/**
 * A class representing a person taking out a loan
 */
public class Loanee {
    private int money;

    /**
     * Construct a loanee object given an amount of money (in dollars)
     * @param money the amount of dollars the person has
     */
    public Loanee(int money) {
        this.money = money;
    }

    /**
     * Gets the money the Loanee has
     * @return the money the Loanee has
     */
    // TODO fill in the blanks, use the Loan class as a guide
    public double getMoney() {
        return money;
    }

    /**
     * Determines if this person could pay back a potential loan
     * given back an amount, an interest rate, and how many years
     * it will take for them to pay it all back at once
     *
     * @param amt the amount the loan is for
     * @param ir the interest rate of the loan
     * @param years the number of years to go by before they can
     * pay the loan
     * @return true if the Loanee can pay back the loan, false if
     * they cannot
     */
    public boolean canPayLoan(double amt, double ir, int years) {
        // TODO
        /*
         HINTS:
         Create a loan object with an amount and an interest rate
         Find the cost of that loan after a number of years
         Check if the person has enough money to pay back the loan
        */
	Loan Loan01 = new Loan(amt,ir);
	double amount = Loan01.getAmountDue(years);
	double money = getMoney();
	if (amount <= money) {
		return true;
	} else{
		return false;
	}
	
    }
}
