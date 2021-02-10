package Lab04;

import java.util.ArrayList;
import java.util.Arrays;

public class Test {
	public static void main(String[] args){
		ArrayList<Integer> arrList = new ArrayList<>(Arrays.asList(1,2,3));
		ArrayList<Integer> other = new ArrayList<>(Arrays.asList(1,2,3));
		System.out.println(arrList == other); //prints false. test for yourself if you'd like
		ArrayListPractice newList = new ArrayListPractice();
		int[] array = {1,2,3};
		int[] array2 = {4,5,6,7,8};
		newList.appendArray(array);
		System.out.println(newList.getArrList());
		newList.intRemoveAll(1);
		System.out.println(newList.getArrList());
		newList.appendArray(array2);
		System.out.println(newList.isEqual(other));
		System.out.println(newList.sumElementWise(other));
		System.out.println(newList.getArrList());
	}
}
