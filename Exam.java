package newJavaProject;
import java.util.*;

abstract class Exam
{
	Scanner sc;
	int marks;
	//Course course;
	int temp;
	
	public Exam()
	{
		marks = 0;
		temp = 0;
		// TODO Auto-generated constructor stub
	}
	
	public Exam(int m)
	{
		marks = m;
		//course = c;
	}

}

class ISA extends Exam
{
	private Scanner sc;

	ISA()
	{
		super();
	}
	
	ISA(int m)
	{
		super(m);
	}
	
	void assignMarks()
	{
		System.out.println("Enter the marks ");
		sc = new Scanner(System.in);
		temp = sc.nextInt();
		System.out.println("Saved..........");
	}
	
	void displayISA()
	{
		System.out.println("Marks: " + marks);
	}
}

class ESA extends Exam
{
   

	ESA()
	{
		super();
	}
	
	ESA(int m)
	{
		super(m);
	}
	
	void assignMarks()
	{
		System.out.println("Enter the marks ");
		sc = new Scanner(System.in);
		temp = sc.nextInt();
		System.out.println("Saved..........");
	}
	
	void displayISA()
	{
		System.out.println("Marks: " + marks);
	}
}
