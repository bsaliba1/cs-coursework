package assignment06p2;

import java.util.Arrays;

public class Array2Dexamples {
	public static int columnLength(int[][]ar,int colnum) {
		int count = 0;
		for(int i = 0;i<ar.length;i++) {
				if(ar[i].length>=colnum) {
					count++;
			}
		}
		return count;
	}
	public static int longestRow(int[][]ar) {
		int rownum = 0;
		int max = 0;
		for(int i= 0; i<ar.length;i++) {
			if(ar[i].length>max) {
				max = ar[i].length;
				rownum = i+1;
			}
		}
		return rownum;
	}
	public static int longestColumn(int[][]ar) {
		int columnnum = 1;
		int index= 0;
		return longHelper(ar,index,columnnum);
	}
	private static int longHelper(int[][]ar,int index, int num) {
		int max = ar[0].length;
		if(index!= ar.length) {
			if(columnLength(ar,index)<max) {
				return longHelper(ar,index+1,num);
			}else{
				num = index + 1;
				return longHelper(ar,index+1,num);
			}
		}
		return num;
	}
	public static int[] rowSums(int[][]ar) {
		int[] retVal = new int[ar.length];
		for(int i = 0; i<ar.length;i++) {
			int x = 0;
			for(int j = 0; j<ar[i].length;j++) {
				x = x + ar[i][j];
			}
			retVal[i] = x;
		}
		return retVal;
	}
	public static int[] columnSums(int[][]ar) {
		int[] retVal = new int[ar[longestRow(ar)-1].length];
		for (int q=0; q<retVal.length;q++) {
			boolean setY=false;
			int y = 0;
			for(int e=0;e<ar.length;e++) {
				if(q<ar[e].length) {
					y += ar[e][q];	
					setY = true;
				}
			}
			if(setY) {
			retVal[q] = y;
			}
		}
		return retVal;
	}
	public static double[] rowAverages(int[][]arr) {
		double[] retVal = new double[arr.length];
		int[] x = rowSums(arr);
		for(int i=0; i<arr.length;i++) {
			int numterms = arr[i].length;
			retVal[i] = (double)x[i]/numterms;
		}
		return retVal;
	}
	public static double[] columnAverages(int[][]arr) {
		double[] retVal = new double[arr[0].length];
		int[] x = columnSums(arr);
		for(int i= 0; i<longestRow(arr);i++) {
			retVal[i] = (double)x[i]/columnLength(arr,i);
		}
		return retVal;
	}
	public static int diagonalSum(int[][]ar) {
		int sum = 0;
		for(int i=0; i<ar.length;i++) {
			for(int j = 0; j<ar.length;j++) {
				if(i==j) {
					sum = sum + ar[i][j];
				}
			}
		}
		return sum;
	}
	public static int antiDiagonalSum(int[][]ar) {
		int sum =0;
		for(int i=0; i<ar.length; i++) {
			for(int j=0; j<ar.length;j++) {
				if((i+j)==ar.length-1) {
					sum = sum + ar[i][j];
				}
			}
		}
		return sum;
	}
	public static void main(String[] args) {
		int[][] test = {{1,7,2,4}, {3,5}, {4,0,2,1,4}};
		int[][]test1 = {{1,7,2,4},{3,5,6,1},{5,5,1,1},{4,0,2,1}};
		System.out.println(columnLength(test,5));
		System.out.println(longestRow(test));
		System.out.println(longestColumn(test));
		System.out.println(Arrays.toString(rowAverages(test)));
		System.out.println(diagonalSum(test));
		System.out.println(antiDiagonalSum(test1));
		System.out.println(Arrays.toString(columnSums(test)));
		System.out.println(Arrays.toString(columnAverages(test)));
	}
}
