package assignment04;
import java.util.Scanner;
/**
 * A question with a text and an answer.
 */
public class Question {
	private String text;
	private String answer;
	/**
	 * Constructs the Question with the questions text and
	 * the correct answer if available
	 * @param qText the text of the question
	 * @param correctResponse the correct answer if available
	 */
	public Question(String qText, String correctResponse) {
		text = qText;
		answer = correctResponse;
	}
	
	//setText is no longer needed

	/**
	 * Sets the answer for this question. It may need to changed from
	 * the one given in the constructor.
	 * @param correctResponse the answer
	 */
	public void setAnswer(String correctResponse) {
		answer = correctResponse;
	}
	/**
	 * Checks a given response for correctness.
	 * @param response the response to check
	 * @return true if the response was correct, false otherwise
	 */
	public boolean checkAnswer(String response) {
		return response.equals(answer);
	}
	/**
	 * Displays this question.
	 */
	public void display() {
		System.out.println(text);
	}
	/**
	 * Presents a question to the user and checks the response.
	 */
	public void presentQuestion() {
		display();
		System.out.print("Your answer: ");
		Scanner in = new Scanner(System.in);
		String response = in.nextLine();
		System.out.println(checkAnswer(response));
	}

}