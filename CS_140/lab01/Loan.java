package lab01;

/**
 * A class representing a loan
 */
public class Loan {
    private double amount; // amount the loan is for
    private double interestRate; // rate the loan takes on interest

    /**
     * Construct a loan object given a loan amount
     * and an interest rate
     *
     * @param amt the amount of the loan
     * @param ir the interest rate
     */
    public Loan(double amt, double ir) {
        this.amount = amt;
        this.interestRate = ir;
    }

    /**
     * Gets the amount the loan is for
     *
     * @return the amount of the loan
     */
    public double getAmount() {
        return amount;
    }

    /**
     * Gets the interest rate of the loan
     *
     * @return the interest rate of the loan
     */
    public double getInterestRate() {
        return interestRate;
    }

    /**
     * Return the amount to be paid back on the loan,
     * given a number of years that have passed
     *
     * @param years the amount of years that have passed
     * @return the amount due on the loan after `years` years have passed
     */
    public double getAmountDue(int years) {
        double amt = amount;
        for (int i = 0; i < years; i++) {
            amt += amt * interestRate;
        }
        return amt;
    }
}
   
