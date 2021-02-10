package assignment07;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.stream.Stream;

public class P19_2 {
	public static boolean palindrome(BigInteger n) {
		boolean retVal= false;
		StringBuilder string = new StringBuilder(n.toString());
		if(string.reverse()==string) {
			retVal =true;
		}
		return retVal;
	}
	public static void main(String[] args) {
		try (PrintWriter output = new PrintWriter("test3.txt")) {
			Stream.iterate(BigInteger.ONE, n-> n.add(BigInteger.ONE)).
					map(n->n.multiply(n)).
					filter(P19_2::palindrome).
					limit(90).
					forEach(output::println);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
