class BvbEmployee
{
	int empId;
	String empName;
	String designation;
	String empType;
	Salary salary;
	String dept;
	BvbEmployee(){}
	BvbEmployee(int empId, String empName, String designation, String empType, String dept)
	{
	this.empId=empId;
	this.empName=empName;
	this.designation=designation;	
	this.empType=empType;
	this.salary=null;
	this.dept=dept;
	}
	public String toString()
	{
	return this.empId+":"+this.empName+":"+this.designation+":"+this.salary+":"+
	this.dept;
	}
	
}
class Salary
{
	double basic;
	double da;
	double hra;
	Salary(){}
	Salary(double basic)
	{
	this.basic=basic;
	this.da=this.basic*0.6;
	this.hra=this.basic*0.15;
	}
	public String toString()
	{
	return this.basic+":"+this.da+":"+this.hra;
	}
}
class Employer
{
	String employerId;
	String employerName;
	BvbEmployee[] bvbEmployees;
	Employer(){}
	Employer(String employerId, String employerName )
	{
		this.employerId=employerId;
		this.employerName=employerName;
	}
	public String toString()
	{
	return this.employerId+":"+this.employerName+bvbEmployees[0];
	}
	void hireEmployee()
	{
	this.bvbEmployees=new BvbEmployee[3];
	bvbEmployees[0]=new BvbEmployee(1001,"aaa","Prof","Teaching", "CSE");
	bvbEmployees[1]=new BvbEmployee(1002,"bbb","Assoc Prof","Teaching", "CSE");
	bvbEmployees[2]=new BvbEmployee(1001,"ccc","Asst Prof","Teaching", "CSE");
	}
	void paySalary(BvbEmployee[] employees)
	{
		for(int i=0;i<employees.length;i++)
		{
		if(employees[i].designation.equals("Prof"))
		{employees[i].salary=new Salary(85000);}
		
		else if(employees[i].designation.equals("Assoc Prof"))
		{employees[i].salary=new Salary(65000);}
		else
		{
		employees[i].salary=new Salary(45000);
		}
		}
	}
	void printEmployees()
	{
	for(int i=0;i<bvbEmployees.length;i++)
	System.out.println(bvbEmployees[i]);
	}

}
class EmployerDemo
{
	public static void main(String[] args)
	{
		Employer employer=new Employer("bvb21","KLE");		
		employer.hireEmployee();
		employer.paySalary(employer.bvbEmployees);
		employer.printEmployees();		
	}
}	