package lab03;
import java.io.File;
import java.util.Scanner;
import java.util.Arrays;
/*The constructor will populate array with integers read from the file with name filename. The body of your constructor will start off with*/

public class ArrayFromFile{
	private int[] array;
	
	public ArrayFromFile(String filename){
		try(Scanner sc = new Scanner(new File(filename))){
			int x = sc.nextInt();
			int[] array = new int[x];		
			for (int i=1 ; i<x; i++) {
				int n = sc.nextInt();
				array[i] = n;
			}		
		}catch(Exception e){
			array = new int[] {};

		}
		
	}
	public int[] getArray(){
		return array;
	}
	public String toString(int[] array){
		return Arrays.toString(array);
	}
	public void removeOddElements(){
		int[] tempArray = getArray();
		int length = tempArray.length;
		int count = 0;			
		for(int i=1;i<length;i++){
			if(tempArray[i]%2 ==0){
			count = count+1;
			}
		}
		array = tempArray;	
	}
}
