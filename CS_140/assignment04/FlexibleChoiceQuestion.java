package assignment04;
import java.util.Set;
import java.util.HashSet;
import java.util.Scanner;

public class FlexibleChoiceQuestion extends ChoiceQuestion{
	private Set<String> answers = new HashSet<String>();

	public FlexibleChoiceQuestion(String qText){
		super(qText);
	}
	public void addChoice(String choice, boolean correct){
		super.addChoice(choice, correct);
		throw new UnsupportedOperationException("Uset the one-argument version");
	}
	public void addChoice(String choice){
		super.addChoice(choice, false);
	}
	public void addAnswer(int i){
		if(i<=0){
			throw new IllegalArgumentException("Answers must be numbered from 1");
		}else{
			if (answers.size()<1){
			super.setAnswer(Integer.toString(i));
			}	
			answers.add(""+i);
		}
	}
	public boolean checkAnswer(String response){
		if(answers.size()==1){
			return super.checkAnswer(response);
		}else{
			String[] parts = response.trim().split("\\s+");
			Set<String> responses = new HashSet<String>();
			for(int i = 0; i<parts.length;i++){
				responses.add(parts[i]);
			}
			if(responses.size()!= parts.length){
				System.out.println("You have repeated answers");
			}
			if(responses.equals(answers)){
				return true;
			}
			int temp = responses.size();
			responses.removeAll(answers);
			if(responses.size()==0){
				System.out.println("Your answers were correct but you missed some");
				return false;
			}
			if(responses.size()<temp){
				System.out.println("You have some correct and some incorrect answers");
				return false;
			}else{
				System.out.println("All your answers were wrong");
				return false;
			}
		}
	}
	public void presentQuestion(){
		if (answers.size()==1){
			super.presentQuestion();
		}else{
			display();
			System.out.print("Your answer(separate multiple answers by space: ");
			Scanner in = new Scanner(System.in);
			String response = in.nextLine();
			System.out.println(checkAnswer(response));
		}
	}

}