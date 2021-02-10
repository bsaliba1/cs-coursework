package assignment07;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class P19_7 {
	public static ArrayList<String> twoSylables() {
		ArrayList<String> array = new ArrayList<String>();
		try(BufferedReader br = new BufferedReader(new FileReader("fem1stnames.text"))){
			while(br.readLine()!=null) {
				String str = br.readLine();
				int count =0;
				for(int i=0; i<str.length();i++) {
					if(str.charAt(i)=='a') count++;
					if(str.charAt(i)=='e') count++;
					if(str.charAt(i)=='i') count++;
					if(str.charAt(i)=='o') count++;
					if(str.charAt(i)=='u') count++;
					if(str.charAt(i)=='A') count++;
					if(str.charAt(i)=='E') count++;
					if(str.charAt(i)=='I') count++;
					if(str.charAt(i)=='O') count++;
					if(str.charAt(i)=='U') count++;
				}
				if(count==2) {
					array.add(str);
				}
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return array;
	}
	public static String longest(ArrayList<String> array) {
		String retVal = "";
		for(int i=0;i<array.size();i++) {
			if(array.get(i).length()>retVal.length()) {
				retVal=array.get(i);
			}
		}
		return retVal;
	}
	public static void main(String[] args) {
		ArrayList <String> array = twoSylables();
		System.out.println(longest(array));
	}
}
