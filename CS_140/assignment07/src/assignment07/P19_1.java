package assignment07;

import java.io.PrintWriter;
import java.util.Random;

public class P19_1 {

	public static void main(String[] args) {
		Random generator = new Random();
		long k = 10;
		for(int i=0;i<10;i++) {
			long t1 = System.currentTimeMillis();
			long count = generator.longs(0, k).parallel().filter(n->n%2==0).limit(k).count();
			long t2 = System.currentTimeMillis();
			System.out.println(count + ": " + (t2-t1));
			k=k*10;
		}
	}

}
