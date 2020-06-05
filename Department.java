package studentdatabase;
import studentdatabase.*;
import java.util.Arrays;

interface Department {
	abstract void outputDepartment(Department d);
	abstract void AddStudent(Student s1);
	abstract void AddCourse(int c1);
	abstract void DisplayStudent();
	abstract void DisplayCourse();
}




class CSDepartment implements Department
{
	int DepID;
	String DepName;
	int CountStudent,m;
	AllCourse DepCourse[];
	GetCourse g;
	Student s[];
	public CSDepartment( String depName) {
		super();
		DepID = 1;
		DepName = depName;
		CountStudent=0;
		m=0;
	}
	public void outputDepartment(Department d)
	{
		System.out.println(d);	
	}
	@Override
	public String toString() {
		return "CSDepartment [DepID=" + DepID + ", DepName=" + DepName
				+ ", DepCourse=" + Arrays.toString(DepCourse) + ", s="
				+ Arrays.toString(s) + "]";
	}
	public void AddCourse(int c1)
	{
		//DepCourse[m]=g.getCourse(c1);
		m++;
	}
	public void AddStudent(Student s1)
	{
		s[CountStudent]=s1;
		CountStudent++;
	}
	public void DisplayStudent()
	{
		for(int i=0;i<s.length;i++)
		{
			System.out.println(s[i]);
		}
	}
	
	public void DisplayCourse()
	{
		for(int i=0;i<DepCourse.length;i++)
		{
			System.out.println(DepCourse[i]);
		}
		
	}
}





class MechDepartment implements Department
{
	int DepID;
	String DepName;
	int CountStudent,m;
	AllCourse DepCourse[];
	GetCourse g;
	Student s[];
	public MechDepartment( String depName) {
		super();
		DepID = 2;
		DepName = depName;
		CountStudent=0;
		m=0;
	}
	public void outputDepartment(Department d)
	{
		System.out.println(d);	
	}
	@Override
	public String toString() {
		return "CSDepartment [DepID=" + DepID + ", DepName=" + DepName
				+ ", DepCourse=" + Arrays.toString(DepCourse) + ", s="
				+ Arrays.toString(s) + "]";
	}
	public void AddCourse(int c1)
	{
		//DepCourse[m]=g.getCourse(c1);
		m++;
	}
	public void AddStudent(Student s1)
	{
		s[CountStudent]=s1;
		CountStudent++;
	}
	public void DisplayStudent()
	{
		for(int i=0;i<s.length;i++)
		{
			System.out.println(s[i]);
		}
	}
	
	public void DisplayCourse()
	{
		for(int i=0;i<DepCourse.length;i++)
		{
			System.out.println(DepCourse[i]);
		}
		
	}
}






class ENCDepartment implements Department
{
	int DepID;
	String DepName;
	int CountStudent,m;
	AllCourse DepCourse[];
	GetCourse g;
	Student s[];
	public ENCDepartment( String depName) {
		super();
		DepID = 3;
		DepName = depName;
		m=0;
		CountStudent=0;
	}
	public void outputDepartment(Department d)
	{
		System.out.println(d);	
	}
	@Override
	public String toString() {
		return "CSDepartment [DepID=" + DepID + ", DepName=" + DepName
				+ ", DepCourse=" + Arrays.toString(DepCourse) + ", s="
				+ Arrays.toString(s) + "]";
	}
	public void AddCourse(int c1)
	{
		//DepCourse[m]=g.getCourse(c1);
		m++;
	}
	public void AddStudent(Student s1)
	{
		s[CountStudent]=s1;
		CountStudent++;
	}
	public void DisplayStudent()
	{
		for(int i=0;i<s.length;i++)
		{
			System.out.println(s[i]);
		}
	}
	
	public void DisplayCourse()
	{
		for(int i=0;i<DepCourse.length;i++)
		{
			System.out.println(DepCourse[i]);
		}
		
	}
}



class CivilDepartment implements Department
{
	int DepID;
	String DepName;
	int CountStudent,m;
	AllCourse DepCourse[];
	GetCourse g;
	Student s[];
	public CivilDepartment( String depName) {
		super();
		DepID = 4;
		DepName = depName;
		m=0;
		CountStudent=0;
	}
	public void outputDepartment(Department d)
	{
		System.out.println(d);	
	}
	@Override
	public String toString() {
		return "CSDepartment [DepID=" + DepID + ", DepName=" + DepName
				+ ", DepCourse=" + Arrays.toString(DepCourse) + ", s="
				+ Arrays.toString(s) + "]";
	}
	public void AddCourse(int c1)
	{
	//	DepCourse[m]=g.getCourse(c1);
		m++;
	}
	public void AddStudent(Student s1)
	{
		s[CountStudent]=s1;
		CountStudent++;
	}
	public void DisplayStudent()
	{
		for(int i=0;i<s.length;i++)
		{
			System.out.println(s[i]);
		}
	}
	
	public void DisplayCourse()
	{
		for(int i=0;i<DepCourse.length;i++)
		{
			System.out.println(DepCourse[i]);
		}
		
	}
}