package lab01;

/**
 * A simulation class that tests some loanees
 */
public class LoanSimulation {
    public static void main(String[] args) {
        // can $100 cover $100 over 10 years at 0%?
        Loanee person1 = new Loanee(100);
        boolean person1CanPay = person1.canPayLoan(100, 0, 10);
        System.out.println(person1CanPay); // should print true

        // can $100 cover $100 over 1 year at 10%?
        Loanee person2 = new Loanee(100);
        boolean person2CanPay = person2.canPayLoan(100, 0.1, 1);
        System.out.println(person2CanPay); // should print false

        // can $110 cover $100 over 1 year at 10%?
        Loanee person3 = new Loanee(110);
        boolean person3CanPay = person3.canPayLoan(100, 0.1, 1);
        System.out.println(person3CanPay); // should print true
    }
}
