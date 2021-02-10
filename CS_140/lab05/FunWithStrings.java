package lab05;
import java.util.ArrayList;
import java.util.Arrays; 

public class FunWithStrings{
	public static void swapMaxes(ArrayList<String> list1, ArrayList<String> list2){
		String lstring1 = list1.get(0);
		int index1 = 0;
		for(int i=0; i<(list1.size()-1);i++){
			
			if(list1.get(i).length()<list1.get(i+1).length()){
				lstring1 = list1.get(i+1);
				index1 = i+1;
			}
		}
		String lstring2 = list2.get(0);
		int index2 = 0;	
		for(int i=0; i<(list2.size()-1);i++){
			if(list2.get(i).length()<list2.get(i+1).length()){
				lstring2 = list2.get(i+1);
				index2 = i+1;
			}
		}
		list1.set(index1,lstring2);
		list2.set(index2,lstring1);

	}
	
}
