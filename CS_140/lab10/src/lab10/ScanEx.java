package lab10;

import java.io.File;
import java.io.FileReader;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class ScanEx {	
	public void experiment (File file) {
		try (Scanner input = new Scanner(new FileReader(file))) {
			int sum = 0;
			while(input.hasNext()) {
				String line = input.nextLine();
				Scanner temp = new Scanner(line);
				if (temp.hasNextInt()) {
					int i = temp.nextInt(); 
					sum += i;
					System.out.println(i + " -> " + sum);
				}else{
					System.out.println("Clearing line: " + line);
				}
				temp.close();
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
		new ScanEx().experiment(new File(args[0]));
	}
}