package newJavaProject;

public class Course 
{
	int courseId;
	String courseName;
	ISA isa;
	ESA esa;
	int total;
	public Course() 
	{
		courseId = 0;
		courseName = " ";
		// TODO Auto-generated constructor stub
	}
	
	public Course(int ci, String cn)
	{
		courseId = ci;
		courseName = cn;
	}
	
	void displayCourse()
	{
		System.out.println("Course ID: " + courseId + "\n" + "Course Name: " + courseName);
		System.out.println("ISA Marks: " + isa.marks + "\n" + "ESA Marks: " + esa.marks);
		total = isa.marks + esa.marks;
		System.out.println("Total Marks: " + total);
	}
}
