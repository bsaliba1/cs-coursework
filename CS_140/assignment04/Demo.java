package assignment04;
import java.util.Set;
import java.util.HashSet;

public class Demo{
	public static void main(String[] args){
		FlexibleChoiceQuestion q1 = new FlexibleChoiceQuestion("What is the name of the first US president?");
		q1.addChoice("George Bush");
		q1.addChoice("Barrack Obama");
		q1.addChoice("Baptiste Saliba");
		q1.addChoice("George Washington");
		q1.addAnswer(4);
		try{
			q1.addAnswer(0);
		}catch(IllegalArgumentException e){
			System.out.println('\n'+"EXCEPTION CAUGHT"+'\n');
		}
		q1.presentQuestion();

		FlexibleChoiceQuestion q2 = new FlexibleChoiceQuestion("Who is Batman's sidekick?");
		q2.addChoice("Birdman");
		q2.addChoice("Shrek");
		q2.addChoice("Superman");
		q2.addChoice("Robin");
		q2.addAnswer(4);
		q2.presentQuestion();

		FlexibleChoiceQuestion q3 = new FlexibleChoiceQuestion("Answers are 1 and 2");
		q3.addChoice("1");
		q3.addChoice("2");
		q3.addChoice("3");
		q3.addChoice("4");
		q3.addAnswer(1);
		q3.addAnswer(2);
		q3.presentQuestion();
	}
}