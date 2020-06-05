package studentdatabase;
import studentdatabase.*;

public class Student {
	public int rollno;
	int count;
	public String name;
	//public float per;
	public int ESAMark1,ESAMark2,ISAMark1,ISAMark2,TotalESA,Total;
	int TotalISA;
	public ISAExam E1;
	public ESAExam E2;
	public AllCourse[] StudCourse;
	public AllCourse StudCourse1,StudCourse2;
	public GetCourse g;
	public int DepID;
	

	public Student(int rollno, String name,int Id) {
		super();
		this.rollno = rollno;
		this.name = name;
		this.DepID = Id;
		this.count=0;
	}
	public Student(int rollno, String name,int Id,AllCourse a1,AllCourse a2) {
		super();
		this.rollno = rollno;
		this.name = name;
		this.DepID = Id;
		this.count=0;
		this.StudCourse1=a1;
		this.StudCourse2=a2;
		//StudCourse[0]=a1;
		//StudCourse[1]=a2;
		
	}

	public Student() {
		
	}

	public int getDepID() {
		return DepID;
	}

	public void setDepID(int depID) {
		DepID = depID;
	}

	public int getRollno() {
		return rollno;
	}

	public void setRollno(int rollno) {
		this.rollno = rollno;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	
	public int getESAMark1() {
		return ESAMark1;
	}

	public void setESAMark1(int eSAMark1) {
		ESAMark1 = eSAMark1;
	}

	public int getESAMark2() {
		return ESAMark2;
	}

	public void setESAMark2(int eSAMark2) {
		ESAMark2 = eSAMark2;
	}

	public int getISAMark1() {
		return ISAMark1;
	}

	public void setISAMark1(int iSAMark1) {
		ISAMark1 = iSAMark1;
	}

	public int getISAMark2() {
		return ISAMark2;
	}

	public void setISAMark2(int iSAMark2) {
		ISAMark2 = iSAMark2;
	}

	

	public void SetIsaMarks()
	{
		E1.SetMarks1();
		E1.SetMarks2();
		ISAMark1=E1.getMaxISAMark1();
		ISAMark2=E1.getMaxISAMark2();
	}
	
	public void SetEsaMarks()
	{
		E2.SetMarks1();
		E2.SetMarks2();
		ESAMark1=E2.getMaxISAMark1();
		ESAMark2=E2.getMaxISAMark2();
	}
	public void AddCourse(AllCourse a)
	{
		count++;
		StudCourse[count]=a;
			
	}
	
	void GetDetailsStudent()
	{
		//for(int i=1;i<=StudCourse.length;i++)
		{
			E1=new ISAExam(StudCourse1);
			E1.SetMarks1();
			E1.SetMarks2();
			ISAMark1=E1.getMaxISAMark1();
			ISAMark2=E1.getMaxISAMark2();
			//SetIsaMarks();
			//SetEsaMarks();
			//E2=new ESAExam(StudCourse2);
			E1.SetMarks1();
			E1.SetMarks2();
			ESAMark1=E1.getMaxISAMark1();
			ESAMark2=E1.getMaxISAMark2();
			TotalISA=ISAMark1+ISAMark2;
			TotalESA=ESAMark1+ESAMark2;
			Total=TotalISA+TotalESA;
		}
	}

	void StudentDetails()
	{
		System.out.println("[ StudentRoll="+rollno+", StudentName="+name+"]");
		//for(int i=0;i<StudCourse.length;i++)
		{
			System.out.println("Course="+StudCourse1+"Total ISA="+TotalISA+"Total ESA="+TotalESA);
		}
		
	}

	@Override
	public String toString() {
		return "Student [rollno=" + rollno + ", name=" + name + ", DepID="
				+ DepID + "]";
	}
	
	
	
	
}
