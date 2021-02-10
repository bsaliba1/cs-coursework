package Lab04;

import java.util.ArrayList;
import java.util.Arrays;

public class Roster{
	private ArrayList<Student> classRoster = new ArrayList<>();

	public ArrayList getRoster(){
		return classRoster;
	}
	public void addStudent(Student s){
		classRoster.add(s);
	}
	public void dropStudent(String name){
		for(int i = 0; i<classRoster.size();i++){
			if (classRoster.get(i).getName()==name){
				classRoster.remove(i);
			}
		}
	}
	public String toString(){
		String returnStr = "";
		for (int i = 0; i<classRoster.size();i++){
			returnStr = returnStr+classRoster.get(i).getName()+" , ";
		}
		return returnStr;
	}
	public void sortById(){
	 	for(int i = 0; i < classRoster.size(); i++){
	      	for(int j = 1; j < (classRoster.size()-i); j++){
	            if(classRoster.get(j-1).getId() > classRoster.get(j).getId()){
	                Student temp = classRoster.get(j-1);
	                classRoster.set(j-1,classRoster.get(j));
	                classRoster.set(j,temp);
	            }
	      	}
	  	}
	}
}