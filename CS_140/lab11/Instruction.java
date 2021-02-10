package lab11;

import java.util.Map;
import java.util.TreeMap;

public class Instruction {
	byte opcode;
	int arg;
	
	public Instruction(byte aOpcode, int aArg){
		this.opcode =aOpcode;
		this.arg = aArg;
	}
	public static boolean noArgument(Instruction instr){
		boolean retVal =false;
		if(instr.opcode<24){
			retVal= true;
		}
		return retVal;
	}
	static int numOnes(int x){
		int count=0;
		String string = Integer.toUnsignedString(x,2);
		for(int i=0; i<string.length();i++){
			if(string.indexOf(i)==1){
				count++;
			}
		}
		return count;
	}
	static void checkParity(Instruction instr){
		int num = numOnes(instr.opcode);
		if(num %2 != 0){
			throw new ParityCheckException("This instruction is corrupted");
		}
	}
	public static Map<String, Integer> opcodes = new TreeMap<>();
	public static Map<Integer, String> mnemonics = new TreeMap<>();
	static {
		opcodes.put("NOP", 0);
		opcodes.put("NOT",1);
		opcodes.put("HALT", 2);
		opcodes.put("LOD",3);
		opcodes.put("STO",4);
		opcodes.put("ADD",5);
		opcodes.put("SUB",6);
		opcodes.put("MUL",7);
		opcodes.put("DIV",8);
		opcodes.put("AND",9);
		opcodes.put("JUMP",10);
		opcodes.put("JMPZ",11);
		opcodes.put("CMPL",12);
		opcodes.put("CMPZ",13);
		for(String str : opcodes.keySet()) 
			mnemonics.put(opcodes.get(str), str);
	}
}
