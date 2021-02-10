package assignment01;

public class Student {
	private Person aself;
	private Class class1 = Class.DUMMY_CLASS;
	private Class class2 = Class.DUMMY_CLASS;
	private Class class3 = Class.DUMMY_CLASS;
	private Class class4 = Class.DUMMY_CLASS;
	//Constructor
	public Student (Person aSelf){
		this.aself = aSelf;
	}

	
	//delegate methods for the 4 different class fields
	public void setQualPoints1(double qPoints){
		class1.setQualPoints(qPoints);
	}
	public void setQualPoints2(double qPoints){
		class2.setQualPoints(qPoints);
	}
	public void setQualPoints3(double qPoints){
		class3.setQualPoints(qPoints);
	}
	public void setQualPoints4(double qPoints){
		class4.setQualPoints(qPoints);
	}


	//returns the whole string name using self
	public String getName(){
		return aself.getFirstName()+" "+aself.getMiddleInitial()+" "+aself.getLastName();
	}

	//getter methods for each of the class fields
	public void setClass1(Class aClass1){
		class1 = aClass1;
	}
	public void setClass2(Class aClass2){
		class2 = aClass2;
	}
	public void setClass3(Class aClass3){
		class3 = aClass3;
	}
	public void setClass4(Class aClass4){
		class4 = aClass4;
	}
	//Compute GPA
	public double computeSemesterGPA(){
		double gpa = 0.0;
		double totalPoints = class1.getQualPoints()+class2.getQualPoints()+class3.getQualPoints()+class4.getQualPoints();
		double totalCredits = class1.getNumCredits()+class2.getNumCredits()+class3.getNumCredits()+class4.getNumCredits(); 
		if (totalCredits>0){
			gpa = totalPoints/totalCredits;
			return gpa; 
		}else {
			return gpa;
		}
	}

}
