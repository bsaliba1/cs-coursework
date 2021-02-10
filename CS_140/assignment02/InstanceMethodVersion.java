package assignment02;

public class InstanceMethodVersion{
	private String string;

	public InstanceMethodVersion(String str){
		string = str;
	}
	public String getString(){
		return string;
	}

	public int countSpaces(){ // counts the spaces in the field string
		int i = Utilities02.countSpaces(getString());
		return i;
	}
	public int countSpaces2(){ // counts the spaces in the field string
		int i = Utilities02.countSpaces2(getString());
		return i;
	}
	public String withoutExtraSpaces(){ // returns a copy of the field string without the extra spaces
		String i = Utilities02.withoutExtraSpaces(getString());
		return i;

	}	
	public String first(){ // returns the first word in the field string
		String i = Utilities02.first(getString());
		return i;
	}
	public String rest(){ // returns the remainder of the field string removing the first word
		String i = Utilities02.rest(getString());
		return i;
	}
	public String[] splitOnSpaces(){ // returns an array of the words in the field string SEE BELOW(skip splitOnSpaces1)
		String[] i = Utilities02.splitOnSpaces(getString());
		return i;
	}
	public int[] strLengths(){ // returns an array of the lengths of the words in the field string
		int[] i = Utilities02.strLengths(getString());
		return i;
	}
}