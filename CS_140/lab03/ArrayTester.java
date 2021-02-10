package lab03;
import java.util.Arrays;

public class ArrayTester{
	public static void main(String[] args){
		try{ArrayFromFile testerArray = new ArrayFromFile("index.txt");
		testerArray.removeOddElements();
		System.out.println("Expected: 5,20,8,13,46,7");
		}catch(Exception IllegalArgumentException){
			System.out.println("Requires one argument");
		}

		int[] array2 = new int[5]; 
		System.out.println(Arrays.toString(array2));

		int n = 0;
		for (int i : array2) {
    		i = n;
    		n++; // shorthand to increment by 1
		}
		System.out.println(Arrays.toString(array2));

		String[] strA = {"This","is","my","program"};
		for (String i : strA){
			System.out.print(i+" "+i.length());
		}

	}
}
