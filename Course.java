package studentdatabase;

import studentdatabase.*;

interface AllCourse
{
	abstract void OutPutCourse(AllCourse a);

	abstract int getCourseID();
}


class Java implements AllCourse {
int CourseID;
String CourseName;
public Java() {
	super();
	CourseID = 101;
	CourseName = "Java";
}


public int getCourseID() {
	return CourseID;
}


public void setCourseID(int courseID) {
	CourseID = courseID;
}


public String getCourseName() {
	return CourseName;
}


public void setCourseName(String courseName) {
	CourseName = courseName;
}


public String toString() {
	return "Course [CourseID=" + CourseID + ", CourseName=" + CourseName + "]";
}
public void OutPutCourse(AllCourse a)
{
	System.out.println(a);
}

}



class CPP implements AllCourse {
int CourseID;
String CourseName;
public CPP() {
	super();
	CourseID = 102;
	CourseName = "C++";
}

public int getCourseID() {
	return CourseID;
}

public void setCourseID(int courseID) {
	CourseID = courseID;
}

public String getCourseName() {
	return CourseName;
}

public void setCourseName(String courseName) {
	CourseName = courseName;
}

public String toString() {
	return "Course [CourseID=" + CourseID + ", CourseName=" + CourseName + "]";
}
public void OutPutCourse(AllCourse a)
{
	System.out.println(a);
}

}



class CFD implements AllCourse {
int CourseID;
String CourseName;
public CFD() {
	super();
	CourseID = 103;
	CourseName = "CFD";
}


public int getCourseID() {
	return CourseID;
}


public void setCourseID(int courseID) {
	CourseID = courseID;
}


public String getCourseName() {
	return CourseName;
}


public void setCourseName(String courseName) {
	CourseName = courseName;
}


public String toString() {
	return "Course [CourseID=" + CourseID + ", CourseName=" + CourseName + "]";
}
public void OutPutCourse(AllCourse a)
{
	System.out.println(a);
}

}



class CDMC implements AllCourse {
int CourseID;
String CourseName;
public CDMC() {
	super();
	CourseID = 104;
	CourseName = "CDMC";
}

public int getCourseID() {
	return CourseID;
}

public void setCourseID(int courseID) {
	CourseID = courseID;
}

public String getCourseName() {
	return CourseName;
}

public void setCourseName(String courseName) {
	CourseName = courseName;
}

public String toString() {
	return "Course [CourseID=" + CourseID + ", CourseName=" + CourseName + "]";
}
public void OutPutCourse(AllCourse a)
{
	System.out.println(a);
}

}



class Microcontroller implements AllCourse {
int CourseID;
String CourseName;
public Microcontroller() {
	super();
	CourseID = 105;
	CourseName = "Micro controller";
}

public int getCourseID() {
	return CourseID;
}

public void setCourseID(int courseID) {
	CourseID = courseID;
}

public String getCourseName() {
	return CourseName;
}

public void setCourseName(String courseName) {
	CourseName = courseName;
}

public String toString() {
	return "Course [CourseID=" + CourseID + ", CourseName=" + CourseName + "]";
}
public void OutPutCourse(AllCourse a)
{
	System.out.println(a);
}

}



class LogicGates implements AllCourse {
int CourseID;
String CourseName;
public LogicGates() {
	super();
	CourseID = 106;
	CourseName = "Logic Gates";
}

public int getCourseID() {
	return CourseID;
}

public void setCourseID(int courseID) {
	CourseID = courseID;
}

public String getCourseName() {
	return CourseName;
}

public void setCourseName(String courseName) {
	CourseName = courseName;
}

public String toString() {
	return "Course [CourseID=" + CourseID + ", CourseName=" + CourseName + "]";
}
public void OutPutCourse(AllCourse a)
{
	System.out.println(a);
}

}





class Mechanics implements AllCourse {
int CourseID;
String CourseName;
public Mechanics() {
	super();
	CourseID = 107;
	CourseName = "Mechanics";
}

public int getCourseID() {
	return CourseID;
}

public void setCourseID(int courseID) {
	CourseID = courseID;
}

public String getCourseName() {
	return CourseName;
}

public void setCourseName(String courseName) {
	CourseName = courseName;
}

public String toString() {
	return "Course [CourseID=" + CourseID + ", CourseName=" + CourseName + "]";
}
public void OutPutCourse(AllCourse a)
{
	System.out.println(a);
}

}



class FluidDynamics implements AllCourse {
int CourseID;
String CourseName;
public FluidDynamics() {
	super();
	CourseID = 108;
	CourseName = "Fluid Dynamics";
}

public int getCourseID() {
	return CourseID;
}

public void setCourseID(int courseID) {
	CourseID = courseID;
}

public String getCourseName() {
	return CourseName;
}

public void setCourseName(String courseName) {
	CourseName = courseName;
}

public String toString() {
	return "Course [CourseID=" + CourseID + ", CourseName=" + CourseName + "]";
}
public void OutPutCourse(AllCourse a)
{
	System.out.println(a);
}

}


class GetCourse
{
	public AllCourse new1;
	public void getCourse(int ch)
	{
		
		if(ch==101)
		{
			new1= new Java();
		}
		else if(ch==102)
		{
			new1= new CPP();
		}
		else if(ch==103)
		{
			new1= new CFD();
		}
		else if(ch==104)
		{
			new1= new CDMC();
		}
		else if(ch==105)
		{
			new1= new Microcontroller();
		}
		else if(ch==106)
		{
			new1= new LogicGates();
		}
		else if(ch==107)
		{
			new1= new Mechanics();
		}
		else if(ch==108)
		{
			new1= new FluidDynamics();
		}
		else
		{
			System.out.println("Invalid Course ID");
			//new1=null;
		}
		
	}
	public AllCourse getNew1() {
		return new1;
	}

	
}
