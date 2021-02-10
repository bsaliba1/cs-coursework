package lab11;

public class Test {
	public static void main(String[] args){
		Instruction test1 = new Instruction((byte)00101011,5);
		Instruction test2 = new Instruction((byte)11010101,6);
		Instruction.checkParity(test1);
		Instruction.checkParity(test2);
	}
}
