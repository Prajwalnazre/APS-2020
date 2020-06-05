package newJavaProject;

public class Student
{
	String usn;
	String studentName;
	Course course[];
	int courseCount;
	public Student()
	{
		usn = " ";
		studentName = " ";
		courseCount = 0;
		// TODO Auto-generated constructor stub
	}
	
	public Student(String u, String sn)
	{
		usn = u;
		studentName = sn;
		courseCount = 0;
	}
	
	void registerCourse(Course c)
	{
		course[courseCount] = c;
		courseCount++;
	}
	
	void displayStudent()
	{
		System.out.println("USN: " + usn);
		System.out.println("NAME: " + studentName);
		for(int i = 0; i < courseCount; i++)
		{
			System.out.println("Course Id: " + course[i].courseId);
			System.out.println("Course Name : " + course[i].courseName);
			System.out.println("ISA : " + course[i].isa.marks);
			System.out.println("ESA : " + course[i].esa.marks);
			System.out.println("Total: " + course[i].total);
		}
		
	}
	
}	


