package studentdatabase;
import studentdatabase.*;
import java.util.Scanner;

interface Exam {
	abstract void SetMarks1();
	abstract void SetMarks2();
	abstract void DisplayExam(Exam E); 
}


class ISAExam implements Exam
{
	AllCourse a;
	//Student s;
	int maxISAMark1,maxISAMark2,TotalMarks;
	Scanner scan=new Scanner(System.in);
	public ISAExam() {	
	}
	
	public ISAExam(AllCourse a) {
		super();
		this.a = a;
	}

	public void SetMarks1()
	{
		maxISAMark1=scan.nextInt();
	}
	
	public void SetMarks2()
	{
		maxISAMark2=scan.nextInt();
		TotalMarks=maxISAMark1+maxISAMark2;
	}
	

	public int getMaxISAMark1() {
		return maxISAMark1;
	}

	public int getMaxISAMark2() {
		return maxISAMark2;
	}

	@Override
	public String toString() {
		return "ISAExam [Course=" + a + ", maxISAMark1=" + maxISAMark1
				+ ", maxISAMark2=" + maxISAMark2 + ", TotalMarks=" + TotalMarks
				+ "]";
	}

	public void DisplayExam(Exam E)
	{
		System.out.println(E);
	}
}



class ESAExam implements Exam
{
	AllCourse a;
	//Student s;
	int maxISAMark1,maxISAMark2,TotalMarks;
	Scanner scan=new Scanner(System.in);
	
	
	public ESAExam() {
		
	}
	public ESAExam(AllCourse a) {
		super();
		this.a = a;
	}

	public void SetMarks1()
	{
		maxISAMark1=scan.nextInt();
	}
	
	public void SetMarks2()
	{
		maxISAMark2=scan.nextInt();
		TotalMarks=maxISAMark1+maxISAMark2;
	}
	
	
	

	public int getMaxISAMark1() {
		return maxISAMark1;
	}
	public void setMaxISAMark1(int maxISAMark1) {
		this.maxISAMark1 = maxISAMark1;
	}
	public int getMaxISAMark2() {
		return maxISAMark2;
	}
	public void setMaxISAMark2(int maxISAMark2) {
		this.maxISAMark2 = maxISAMark2;
	}
	@Override
	public String toString() {
		return "ISAExam [Course=" + a + ", maxISAMark1=" + maxISAMark1
				+ ", maxISAMark2=" + maxISAMark2 + ", TotalMarks=" + TotalMarks
				+ "]";
	}

	public void DisplayExam(Exam E)
	{
		System.out.println(E);
	}
}