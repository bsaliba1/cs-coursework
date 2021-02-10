package lab10;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class SumTest {
	public void experiment (File file) {
		try (Scanner input = new Scanner(new FileReader(file))) {
			int sum = 0;
			while(input.hasNextInt()) {
				sum += input.nextInt();
			} 
			System.out.println(sum);
		}catch(InputMismatchException ex3){
			System.out.println(ex3+"--not a number from nextInt()");
		}catch(NoSuchElementException ex) {
			System.out.println(ex);
			System.out.println(ex.getMessage());
			System.out.println(ex + "--nothing left in file");
		} catch(FileNotFoundException ex2){
			System.out.println("File " + file.getName()+ " is not found");
		} catch(Exception ex) {
			ex.printStackTrace();
		}

	}
	public static void main(String[] args) {
		new SumTest().experiment(new File(args[0]));
	}
}
