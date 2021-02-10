package assignment07;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.stream.LongStream;

public class P19_3 {
	public static boolean palindrome(long n) {
		boolean retVal= false;
		StringBuilder string = new StringBuilder(Long.toString(n));
		if(string.reverse()==string) {
			retVal =true;
		}
		return retVal;
	}
	public static boolean prime(long n) {
		long k =0;
		if(n<2) return false;
		if(n==2||n==3)return true;
		if(n%2==0)return false;
		if(n%3==0) {
			return false;
		}
		k=1;
		while(n>=(6*k-1)*(6*k-1)) {
			if(n%(6*k-1)==0||n%(6*k+1)==0) {
				return false;
			}
			k++;
		}
		return true;
	}
	public static void main(String[] args) {
		try(PrintWriter output = new PrintWriter("test4.txt")){
			LongStream.iterate(1, n->n+1).
			filter(P19_3::prime).
			filter(P19_3::palindrome).
			limit(500).
			forEach(output::println);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
