package assignment04;
import java.util.ArrayList;
/**
 * A question with multiple choices.
 */
public class ChoiceQuestion extends Question {
	private ArrayList<String> choices;
	/**
	 * Constructs a ChoiceQuestion with the text of the question
	 * but no correct answer.
	 * @param qText the text of the question
	 */
	public ChoiceQuestion(String qText) {
		super(qText, "");
		choices = new ArrayList<>();
	}
	/**
	 * Adds an answer choice to this question.
	 * @param choice the choice to add
	 * @param correct true if this is the correct choice, false otherwise
	 */
	public void addChoice(String choice, boolean correct) {
		choices.add(choice);
		if (correct) {
			// Convert choices.size() to string
			String choiceString = "" + choices.size();
			setAnswer(choiceString);
		}
	}
	public void display() {
		// Display the question text
		super.display();
		// Display the answer choices
		for (int i = 0; i < choices.size(); i++) {
			System.out.println((i+1) + ": " + choices.get(i));     
		}
	}
}