import java.util.Arrays;
import static lab03.ArrayPractice.*;

public class ArrayPracticeTester{
	public static void test(String expected, int[] actual) {
	    System.out.println("Expected: " + expected +
	                       ", received: " + Arrays.toString(actual));
	}

	public static void test(int[] expected, int[] actual) {
	    System.out.println("Expected: " + Arrays.toString(expected) +
	                       ", received: " + Arrays.toString(actual));
	}

	public static void test(boolean expected, boolean actual) {
	    System.out.println("Expected: " + expected + ", received: " + actual);
	}
	public static void main(String[] args){
		//Just a bunch of TESTS
		int[] simple = {1, 2, 3, 4, 5, 6};
		int[] reversed = {6, 5, 4, 3, 2, 1};
		test("{6, 5, 4, 3, 2, 1}", reverse(simple));
		test("{1, 2, 3, 4, 5, 6}", reverse(reversed));
		test(true, isIncreasing(simple));
		test(false, isIncreasing(reversed));
		System.out.println("Expected: 1.0    Actual is: "+average(new int[]{0,0,0,0,5}));
		test("[1,2,3]",evenIndicesOnly(new int[]{1,0,2,0,3}));
		System.out.println("Expected: {1,2,3,4,5,6,6,5,4,3,2,1}     Actual is: "+Arrays.toString(concatenate(simple,reversed)));
		reverseInPlace(simple);
		test("{6, 5, 4, 3, 2, 1}", simple);
		reverseInPlace(reversed);
		test("{1, 2, 3, 4, 5, 6}", reversed);
		reverseInPlace(null);
		reverseInPlace(new int[0]);
		try{
			average(null);
			System.out.println("test failed - exception not thrown");
		}catch(IllegalArgumentException e) {
	   		System.out.println("caught the expected illegal argument exception");
		}
		try{
			endToEnd(null,null);
			System.out.println("test failed - exception not thrown");
		} catch(IllegalArgumentException e) {
	   		System.out.println("caught the expected illegal argument exception");
		}
		try {
	    	concatenate(null, null);
	    	System.out.println("test failed - exception not thrown");
		} catch(IllegalArgumentException e) {
	   		System.out.println("caught the expected illegal argument exception");
		}
	}
}