package lab05;
import java.util.ArrayList;
import java.util.Arrays;

public class Zipper{
	public static int[] zip(int[] arr1, int[] arr2){
		int[] retval = new int[arr1.length+arr2.length];		
		if( arr1 != null && arr2!=null&& arr1.length==arr2.length){
			int x = 0;
			for(int i=0; i<arr1.length;i++){
				retval[x] = arr1[i];
				x = x+2;
			}
			int y = 1;
			for(int i=0; i<arr2.length;i++){
				retval[y] = arr2[i];
				y = y+2;
			}	
		}else{
			throw new IllegalArgumentException("bad input");
		}
		return retval;
	}
}	
