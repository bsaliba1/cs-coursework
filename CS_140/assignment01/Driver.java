package assignment01;

public class Driver {
	public static void main(String[] args) {
		//Instantiate three Person objects
		Person gwb = new Person("George","Bush",'W');
		Person sdd = new Person("Snoop","Dogg",'D');
		Person cgm = new Person("Conor","McGreggor",'G');
	

		Class aClass1 = new Class("geog","272",101,4);
		aClass1.setQualPoints(4.0);
		Class aClass2 = new Class("cs","110",238,4);
		aClass2.setQualPoints(3.7);
		Class aClass3 = new Class("cs","140",234,4);
		aClass3.setQualPoints(3.3);
		Class aClass4 = new Class("envi","101",237,4);
		aClass4.setQualPoints(3.0);
		Class aClass5 = new Class("writing","111",444,4);
		aClass5.setQualPoints(2.7);
		Class aClass6 = new Class("theater","101",555,4);
		aClass6.setQualPoints(2.3);
		Class aClass7 = new Class("linear","334",232,4);
		aClass7.setQualPoints(2.0);

		//Instantiate three Student objects
		Student s_gwb = new Student(gwb);
		Student s_sdd = new Student(sdd);
		s_sdd.setClass1(aClass1);
		s_sdd.setClass2(aClass2);
		s_sdd.setClass3(aClass3);
		Student s_cgm = new Student(cgm);
		s_cgm.setClass1(aClass4);
		s_cgm.setClass2(aClass5);
		s_cgm.setClass3(aClass6);
		s_cgm.setClass4(aClass7);


		//Print GPAs
		System.out.printlnE(s_gwb.getName()+"'s GPA is: "+s_gwb.computeSemesterGPA());
		System.out.println(s_sdd.getName()+"'s GPA is: "+s_sdd.computeSemesterGPA());
		System.out.println(s_cgm.getName()+"'s GPA is: "+s_cgm.computeSemesterGPA());

	}		
}