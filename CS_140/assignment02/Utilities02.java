package assignment02;
import java.util.Optional;
import java.util.Arrays;

public class Utilities02{
	public static int countNulls(Object[] array){
		int count = 0;
		if(array!= null ){
			if (array.length>=1){
				for(Object i : array){
					if (i == null){
					count ++;
					}
				}
			}else{
				count=0;
			}
		}else {
			count = 0;
		}
		return count;
	}
	public static int countSpaces(String str){
		int count = -1;
		if (str != null){
			count = 0;
			for ( int i=0; i <= str.length()-1; i++){
				if (str.charAt(i) == ' '){
					count ++;
				}
			}
		}
		return count;
	}
	public static int countSpaces2(String str){
		int count = -1;
		if(str != null){
			count = 0;
			for(char c:str.toCharArray()){
				if(c==' '){
					count++;
				}
			}
		}
	return count;
	}
	public static String first(String str){
		String returnVal= null;
		if (str!=null){
			returnVal =  str.trim();
			int i = returnVal.indexOf(' ');
			if (i >= 0) {
				returnVal =returnVal.substring(0,i);
			}
		}
		return returnVal;
	}
	public static String rest(String str){
		String returnVal= " ";
		if (str!=null){
			returnVal = str.trim();
			int i = returnVal.indexOf(' ');
			if (i >= 0) {
				String retVal = returnVal;
				returnVal = retVal.substring(i+1).trim();
			}
		}else{
			returnVal = null;
		}
		return returnVal;
	}
	public static String withoutExtraSpaces(String str){
		String returnVal = null;
		if(str != null){
			returnVal = str.trim();
			int len1 = 0;
			int len2 = 0;
			while(len2<len1){
				len1 = returnVal.length();
				returnVal = returnVal.replace("  "," ");
				len2  = returnVal.length();
				}
		}
		return returnVal;
	}
	public static String[] splitOnSpaces(String str){
		int len = countSpaces(withoutExtraSpaces(str));
		String[] returnVal = null;
		if(len>=0){
			if (str.trim().length()==0){
				returnVal = new String[0];
			}else{
				returnVal = new String[len+1];
			}
			for(int i=1;i<len+1;i++){
				returnVal[i]=first(str);
				str = rest(str);
			} 
		}
		return returnVal;
	}
	public static int[] strLengths(String str){
		String[]stringarr = splitOnSpaces(str);
		int[] array = new int[0];
		if (stringarr.length>1 && stringarr != null){
			array = new int[stringarr.length];
			for(int i = 1; i<stringarr.length;i++){
				String w = stringarr[i];
				array[i] = w.length();
			}
		}
		return array;
	}
	public static Optional<String[]> splitOnSpaces1(String str){
		String[] returnVal=null;
		if(str != null && str.trim().length()>0){
			int len = str.trim().length();
			returnVal = new String[len];
			int index=0;
			while(str.trim().length()!=0){
				returnVal[index]=first(str);
				str = rest(str);
				index++;
			}
			returnVal = Arrays.copyOf(returnVal,index);
			return Optional.of(returnVal);
		}else{
			return Optional.empty();
		}
	}
}
