package newJavaProject;

import java.util.ArrayList;

interface Department
{	
	void addStudent(Student s);
	void conductExam();
	void displayDept();
}

class CS implements Department
{
	ArrayList<Student> st = new ArrayList<Student>();
	//int studentCount = 0;
	@Override
	public void addStudent(Student s)
	{
		st.add(s);
		
		// TODO Auto-generated method stub
		
	}

	@Override
	public void conductExam()
	{
		// TODO Auto-generated method stub
		
	}

	@Override
	public void displayDept()
	{
		// TODO Auto-generated method stub
		
	}
	
}
