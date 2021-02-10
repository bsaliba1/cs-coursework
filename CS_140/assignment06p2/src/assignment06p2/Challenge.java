package assignment06p2;
import static assignment06p2.Array2Dexamples.*;

public class Challenge {
	int[][] array = new int[4][4];
	int[] colSums = new int[4];
	int[] rowSums = new int[4];
	int diagSum;
	int antidiagSum;
	
	public Challenge(int[][] aArray, int[] aColSums, int[] aRowSums, int aDiagSum, int aAntidiagSum) {
		this.array = aArray;
		this.colSums = aColSums;
		this.rowSums = aRowSums;
		this.diagSum = aDiagSum;
		this.antidiagSum = aAntidiagSum;
	}
	public String view (int[][]arr) {
		String retVal = "";
		for(int i=0; i<arr.length;i++) retVal+= '\t';
		retVal += antidiagSum+"\n";
		for(int i = 0; i<arr.length;i++) {
			for(int j=0; j<arr.length;j++) {
				retVal += arr[i][j]+"\t";
			}
			retVal+= rowSums[i]+"\n";
		}
		for(int i=0;i<arr.length;i++) {
			retVal+=colSums[i]+"\t";
		}
		retVal+= diagSum;
		return retVal;
	}
	public int countZeros(int[][] arr) {
		int count=0;
		for(int i=0;i<arr.length;i++) {
			for(int j=0;j<arr.length;j++) {
				if(arr[i][j]==0)count++;
			}
		}
		return count;
	}
	class Pair {
		int row; int col;
		public Pair(int x, int y) {
			row = x;
			col = y;
		}
	}
	public Pair nextZero(int[][] arr) {
		if(countZeros(arr)>0) {
			Pair retVal = nextHelper(arr,0,0);
			return retVal;
		}else {
			return null;
		}
	}
	private Pair nextHelper(int[][]arr,int i,int j) {
		if(arr[i][j]==0) {
			Pair retVal = new Pair(i,j);
			return retVal;
		}
		if(j<arr.length-1) {
			return nextHelper(arr,i,j+1);
		}if(i<arr.length-1) {
			return nextHelper(arr,i+1,0);
		}else {
			return null;
		}
	}
	public boolean feasible (int[][] arr) {
		boolean retVal = true;
		if(antiDiagonalSum(arr)>antidiagSum||diagonalSum(arr)>diagSum) {
			retVal = false;
		}
		for(int i = 0; i<4;i++) {
			if(rowSums(arr)[i]> rowSums[i]) {
				retVal= false;
			}
		}
		for(int j = 0; j<4;j++) {
			if(columnSums(arr)[j]> colSums[j]) {
				retVal = false;
			}
		}
		return retVal;
	}
	public boolean solved(int[][] arr) {
		boolean retVal = true;
		if(antiDiagonalSum(arr)!= antidiagSum ||
				diagSum!= diagonalSum(arr)) retVal = false;
		for(int i = 0; i<arr.length;i++) {
			if(rowSums(arr)[i]!= rowSums[i]) {
				retVal= false;
			}
		}
		for(int i = 0; i<arr.length;i++) {
			if(columnSums(arr)[i]!= colSums[i]) {
				retVal=false;
			}
		}
		return retVal;
	}
	public int[][] duplicate (int[][] arr){
		int[][] dup = new int[arr.length][arr[0].length];
		for(int i= 0; i<arr.length;i++) {
			for(int j = 0; j<arr.length;j++) {
				dup[i][j]= arr[i][j];
			}
		}
		return dup;
	}
	public void solve(int[][]arr) {
		if(countZeros(arr)>0) {
			Pair p = nextZero(arr);
			for(int i=1; i<=9;i++) {
				arr[p.row][p.col] = i;
				if(countZeros(arr)==0 && solved(arr)) {
				System.out.println("\nSolution\n"+view(arr));
				}
				if(countZeros(arr)>0 && feasible(arr)) {
					solve(duplicate(arr));
				}
			}
		}
	}
	public static void main(String[] args) {
		Challenge puzzle = new Challenge(new int[][]{{2,0,0,0},{0,0,0,1},{0,5,0,0},{0,0,6,0}},
				new int[]{8,9,15,28}, new int[]{15,11,17,17}, 14, 20);
		System.out.println(puzzle.view(puzzle.array));
		puzzle.solve(puzzle.duplicate(puzzle.array));
	}
}
