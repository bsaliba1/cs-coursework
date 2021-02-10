package assignment02;
import java.util.Arrays;
import java.util.Optional;

public class Tester{
	public static void main(String[] args){
		System.out.println("Expected value 0");
		System.out.println(Utilities02.countNulls(null));
		Object[] test = {}; 
		System.out.println("Expected value 0");
		System.out.println(Utilities02.countNulls(test));
		String[] test_s = new String[6];
		
		//countSpaces test
		test_s[0] = "This is a test";
		test_s[1] = "Thisis a test";
		test_s[2] = "Thisisa test";
		test_s[3] = "Thisisatest";
		test_s[4] = "";
		test_s[5] = null;
		Object[] results = new Object[]{3,2,1,0,0,-1};
		int n =0;
		for(String i:test_s){
			System.out.println("Expected: "+results[n]);
			System.out.println(Utilities02.countSpaces(i));
			n++;
		}
		n=0;
		for(String i:test_s){	
			System.out.println("Expected: "+results[n]);
			System.out.println(Utilities02.countSpaces2(i));
			n++;
		}	//WithoutSpaces test
		n=0;
		for(String i:test_s){
			System.out.println(Utilities02.withoutExtraSpaces(i));

		}

		//first test
		System.out.println("Expected: null Actual: "+Utilities02.first(null));
		System.out.println("Expected:  Actual:  "+Utilities02.first(""));
		System.out.println("Expected:      Actual:" +Utilities02.first("    "));
		System.out.println("Expected:   hello   Actual:" +Utilities02.first("hello"));

		//rest test
		System.out.println("Expected: null Actual: "+Utilities02.rest(null));
		System.out.println("Expected:  Actual: "+Utilities02.rest(""));
		System.out.println("Expected:       Actual: "+Utilities02.rest("    "));
		System.out.println("Expected:   hello   Actual: " +Utilities02.rest("hello"));

		//DID NOT WORK SplitonSpaces test
		System.out.println("Expected: null Actual: "+Utilities02.splitOnSpaces(null));
		System.out.println("Expected: [] Actual: "+Arrays.toString(Utilities02.splitOnSpaces("")));
		System.out.println("Expected: [Hello,my,name,is,Baptiste] Actual: "+Arrays.toString(Utilities02.splitOnSpaces("Hello my name is Baptiste Saliba")));

		System.out.println("Expected: null"+Utilities02.splitOnSpaces1(null));
		System.out.println("Expected: "+Utilities02.splitOnSpaces1(""));
		//DID NOT WORK System.out.println("Expected:      "+Utilities02.splitOnSpaces1("Hello how are you my name is Baptiste Saliba"));

		//DID NOT WORK System.out.println("Expected: null"+Utilities02.strLengths(null));
		//DID NOT WORK System.out.println("Expected: "+Utilities02.strLengths(""));
		System.out.println("Expected:     "+Arrays.toString(Utilities02.strLengths("Hello how are you my name is Baptiste")));

		/*DID NOT WORK Optional<String[]> array = Utilities02.splitOnSpaces1(" should give an array of   these words  separated by commas   ");
		if(array.isPresent()) {
			System.out.println(Arrays.toString(array.get()));
		} else {
			System.out.println("The input was null or empty");
		}*/

		System.out.println("THIS IS THE INSTANCE METHOD TEST");


		InstanceMethodVersion ime1 = new InstanceMethodVersion("This is a test");
		System.out.println("Expected: 3 Actual: "+ime1.countSpaces());
		System.out.println("Expected: 3 Actual: "+ime1.countSpaces2());
		System.out.println("Expected: his is a test Actual: "+ime1.withoutExtraSpaces());
		System.out.println("Expected: This Actual: "+ime1.first());
		System.out.println("Expected: is a test Actual: "+ime1.rest());
		System.out.println(Arrays.toString(ime1.splitOnSpaces()));
		System.out.println("Expected: [0, 4, 2, 1] is a test Actual: "+Arrays.toString(ime1.strLengths()));
		InstanceMethodVersion ime2 = new InstanceMethodVersion("Hello how are you I'm Baptiste");
		System.out.println("Expected: 5 Actual: "+ime2.countSpaces());
		System.out.println("Expected: 5 Actual: "+ime2.countSpaces2());
		System.out.println("Expected: Hello how are you I'm Baptiste Actual: "+ime2.withoutExtraSpaces());
		System.out.println("Expected: Hello Actual:"+ime2.first());
		System.out.println("Expected: Hello how are you I'm Baptiste Actual: "+ime2.rest());
		System.out.println(Arrays.toString(ime2.splitOnSpaces()));
		System.out.println("Expected: [0, 5, 3, 3, 3, 3] is a test Actual: "+Arrays.toString(ime2.strLengths()));
		InstanceMethodVersion ime3 = new InstanceMethodVersion("jasnk jkanfn knaskn kjk a");
		System.out.println("Expected: 4 Actual: "+ime3.countSpaces());
		System.out.println("Expected: 4 Actual: "+ime3.countSpaces2());
		System.out.println("Expected: jasnk jkanfn knaskn kjk a Actual: "+ime3.withoutExtraSpaces());
		System.out.println("Expected: jasnk Actual:"+ime3.first());
		System.out.println("Expected: jkanfn knaskn kjk a Actual: "+ime3.rest());
		System.out.println(Arrays.toString(ime3.splitOnSpaces()));
		System.out.println("Expected: [0, 5, 6, 6, 3] Actual: "+Arrays.toString(ime3.strLengths()));

	}
}