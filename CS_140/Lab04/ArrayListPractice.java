package Lab04;

import java.util.ArrayList;
import java.util.Arrays; 

public class ArrayListPractice{
	private ArrayList<Integer> arrList = new ArrayList<>();

	public int intRemoveAll(int e){	
		int a = arrList.size(); 
		for (int i=0;i<arrList.size();i++){
			if(arrList.get(i)==e){
				arrList.remove(i);
			}		
		}
		int b = arrList.size();
		int returnVal= a-b;
		return returnVal;	
	}
	public boolean isEqual(ArrayList<Integer> other){
		boolean returnVal= true;
		if (arrList.size()==other.size()){
			for(int i=0;i<arrList.size();i++){
				if(arrList.get(i)!=other.get(i)){
					returnVal= false;		
				}
			}
		}
		else{
			returnVal= false;
		}
		return returnVal;
	}
	public void appendArray(int[] arr){
		if (arr!=null){
			for(int i = 0; i<arr.length; i++){
				int x = arr[i];
				arrList.add(x);
			}
		}else {
			throw new IllegalArgumentException("Illegal Argument");
		}
	}

	public ArrayList sumElementWise(ArrayList<Integer> other){
		ArrayList<Integer> returnList = new ArrayList<>();
		if (other != null){		
			if (arrList.size()>=other.size()){
				for (int i = 0; i<other.size();i++){
					int z = arrList.get(i)+other.get(i);
					returnList.add(z);				
				}
			}else {
				for (int i = 0; i<arrList.size();i++){
					int x = arrList.get(i)+other.get(i);
					returnList.add(x);				
				}
			}
		return returnList;		
		}else{
			throw new IllegalArgumentException("Illegal Argument");
		}
	}
	public ArrayList getArrList(){
		return arrList;
	}
}
