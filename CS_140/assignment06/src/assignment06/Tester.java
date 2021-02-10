package assignment06;
import java.util.ArrayList;
import java.util.Collections;
import assignment06.TriangleClassifier.Triple;
import static assignment06.TriangleClassifier.createTriple;
import static assignment06.TriangleClassifier.removeScalene;

public class Tester {
	public static void main(String[] args) {
		ArrayList<Triple> test = new ArrayList<Triple>();
		Triple a = createTriple(1,1,3);//obtuse isoscles
		Triple b = createTriple(4,6,9);//obtuse scalene
		Triple c = createTriple(15,21,22);//acute scalene
		Triple d = createTriple(4,4,4);//Equilateral
		Triple e = createTriple(5,5,6);//acute isosceles
		Triple f = createTriple(0,0,0);//throws exception
		test.add(a);
		test.add(b);
		test.add(c);
		test.add(d);
		test.add(e);
		test.toString();
		System.out.println(test.toString());
		Collections.sort(test);
		System.out.println(test.toString());
		removeScalene(test);
		System.out.println(test.toString());
		try {
			test.add(f);
			test.toString();
		}catch(IllegalArgumentException x) {
			System.out.println("Exception Caught");
		}
	}
}
