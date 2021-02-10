package lab03;
import java.util.Arrays;

public class ArrayPractice{
	public static double average(int[] array){
		double nums = 0.0;
		double average = 0.0;
		if(array!=null){
		for(int i:array){
			nums = nums+i;
		}
		average = nums/array.length;
		}else{
			throw new IllegalArgumentException("Argument was null");
		}
		return average;
	}
	public static int[] evenIndicesOnly(int[] array){
		boolean isEven = true;
		if(array.length%2==1){
			isEven = false;
		}
		if (isEven==true){
			int[] array2 = new int[array.length/2];
			int n=0;
			for(int i = 0;i<=array.length;i=i+2){
				array2[n] = array[i];
				n++;
			}
			return array2;
		}else{ 
			int[] array2 = new int[(array.length/2)+1];
			int n=0;
			for(int i = 0;i<=array.length;i=i+2){
				array2[n] = array[i];
				n++;
			}
			return array2;
		}
		
	}
	public static boolean isIncreasing(int[] array){
		boolean w = false;
		for(int i = 1;i<array.length-1;i++){
			int n = i+1;
			if(array[n]>array[i]){
				w = true;
			}
		}
		return w;
	}
	public static int[] reverse(int[] array){
		int n = 0;
		int[] array2 = new int[array.length];
		for(int i=array.length-1;i>=0;i=i-1){
			array2[n]=array[i];
			n++;
		}
		return array2;
	}
	public static int[] concatenate(int[] arr1, int[] arr2){
		int[] array3 = new int[0];
		if(arr1 !=null && arr2!=null){
			int x = arr1.length + arr2.length;
			array3 = new int[x];
			int n = 0;
			for(int i:arr1){
				array3[n]= i;
				n++;
			}
			n = arr1.length;
			for(int k:arr2){
				array3[n]= k;
				n++;
			}
		}else{	
			throw new IllegalArgumentException("Both arrays cannot be null");
		}
		return array3;
	}
	public static int[] endToEnd(int[] arr1, int[] arr2){
		int n=0;
		int[] array2 = new int[0];
		if (arr1!=null && arr2!=null){
			array2 = new int[arr1.length+arr2.length];
			for(int i:arr1){
			array2[n]= i;
			n++;
			}
			n=3;
			for(int k:reverse(arr2)){
				array2[n]= k;
				n++;
			}
		}else{
			throw new IllegalArgumentException("Both arrays cannot be null");
		}
		return array2;
	}
	public static void reverseInPlace(int[] array){
		if (array == null){
			array = null;
		}else{
		int n = 0;
		for (int i=0;i<array.length/2;i++){
			n = array[i];
			array[i]= array[array.length-1-i];
			array[array.length-1-i]= n;
		}
		}
	}
}