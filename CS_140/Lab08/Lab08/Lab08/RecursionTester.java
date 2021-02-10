package Lab08;
import java.util.ArrayList;
import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class RecursionTester {
	@Test
	void factorialTest() {
		try{
			assertEquals(1,Recursion.factorial(0),1e-6);
			assertEquals(1,Recursion.factorial(1),1e-6);
			assertEquals(120,Recursion.factorial(5),1e-6);
		}catch(AssertionError e) {
			System.out.println("TestFailed");
			throw e;
		}
	}
	@Test
	void squareRootTest() {
		try{
		assertEquals(0,Recursion.squareRoot(0),1e-6);
		assertEquals(1,Recursion.squareRoot(1),1e-6);
		assertEquals(4,Recursion.squareRoot(16),1e-6);
		}catch(AssertionError e) {
			System.out.println("TestFailed");
			throw e;
		}
	}
	@Test
	void sumArrayListTest() {
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(1);
		list.add(2);
		list.add(3);
		try{
			assertEquals(6,Recursion.sum(list),1e-6);
		}catch(AssertionError e) {
		System.out.println("TestFailed");
		throw e;
	}
	}
	@Test
	void sumIntTest() {
		try{
			assertEquals(6,Recursion.sum( new int[] {1,2,3}),1e-6);
		}catch(AssertionError e) {
			System.out.println("TestFailed");
			throw e;
		}
	}
	@Test
	void binomialCoefficientTest() {
		try{
		assertEquals(84,Recursion.binomialCoefficient(9,3),1e-6);
		assertEquals(10,Recursion.binomialCoefficient(5,3),1e-6);
		}catch(AssertionError e) {
			System.out.println("TestFailed");
			throw e;
		}
	}

}
