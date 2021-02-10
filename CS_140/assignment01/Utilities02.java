package assignment02;

public class Utilities02{
	public static int countNulls(Object[] array){
		int count = 0;
		for(int i : array){
			if i == null{
			count ++;
			}
		}	
		return count;
	}
	public static int countSpaces(String str){
		int count = -1;
		if (str != null){
			count = 0;
			for ( int i=0; i <= str.length; i++){
				if (str.charAt(i) = " "){
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
			for(int c:str.toCharArray()){
				if(str[c]==" "){
					count++;
				}
			}
		}
	return count;
	}
	public static String first(String str){
		String returnVal= null;
		if (str!=null){
			returnVal =  str.trim;
			int i = returnVal.indexOf(' ');
			if (i >= 0) {
				returnVal =returnVal.substring(0,i);
			}
			return returnVal;
		}
	}
	public static String rest(String str){
		String returnVal= ' ';
		if (str!=null){
			returnVal =  str.trim;
			int i = returnVal.indexOf(' ');
			if (i >= 0) {
				retVal = returnVal;
				returnVal = retVal.substring(i+1).trim();
			}
			return returnVal;
		}
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
				len2  = returnVal.length;
				}

			}
		return returnVal;
	}
	public static String[] splitOnSpaces(String str){
		int len = countSpaces(withoutExtraSpaces(str));
		if (len!= 0){
			words = len + 1;
		}else {
			if (str.length==0 && str.trim().length == 0){
				words = 0;
			}else{
				words = 1;
			}
		String[] returnVal = null;
		if(len>=0){
			if (str.trim().length()==0){
				returnVal = {};
			}else{
				returnVal = {len+1};
			}
			for(int i=1;i<len;i++){
				returnVal[i]=first(str);
				str = rest(str);
			} 
		}

	}		
		String [] returnVal = null;	
		if(len>=0){
			if (str.trim().length() ==0){}
		}
	}
}