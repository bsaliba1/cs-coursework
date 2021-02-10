package lab05;
import java.util.ArrayList;
import java.util.Arrays; 

public class Division{
	private ArrayList<Double> list = new ArrayList<Double>();
	
	public Division(double[] array){
		if(array!= null && array.length!=0){
			for(int i= 0; i<array.length;i++){
				list.add(array[i]);
			}
		}else{
			throw new IllegalArgumentException("need to enter an array with at least one double");
		}			
	}
	public void removeZeroes(){
		for(int i=0; i<list.size();i++){
			if(list.get(i)==0){
				list.remove(i);
			}		
		}
	}
	public void divide(int divisor){
		if(divisor!=0){
			for(int i=0; i<list.size();i++){
				list.set(i,(list.get(i)/divisor));
			}	
		}else{
			throw new IllegalArgumentException("cannot divide by zero");
		}
	}
	public String toString(){
		String str = list.toString();
		return str;
	}	
}
