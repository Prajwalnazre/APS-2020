// Array programs

class ArrayDemo1
{
	public static void main(String[] args)
	{
		// array variable
		int[] marks=new int[5];
		marks[0]=10;
		marks[1]=11;
		marks[2]=12;
		marks[3]=13;
		marks[4]=14;
		//print array elements individually
		System.out.println(marks[0]);
		System.out.println(marks[1]);
		System.out.println(marks[2]);
		System.out.println(marks[3]);
		System.out.println(marks[4]);
		
		//print array elements using for loop

		for(int i=0;i<5;i++)
		System.out.println(marks[i]);		

		// using for each 
		// syntax: for(type new_var_name: array_variable_name )
		for(int m: marks)
		System.out.println(m);	
		
		//char
		char[] letters=new char[5];
		letters[0]='a';			
		letters[1]='b';
		letters[2]='c';
		letters[3]='d';
		letters[4]='e';
		for(char c: letters)
		System.out.println(c);	
		//String array
		String[] deptName=new String[5];
		deptName[0]="CSE";
		deptName[1]="ISE";
		deptName[2]="Mech";
		deptName[3]="EC";
		deptName[4]="CIVIL";
		
		for(String  dnames: deptName)
		{
		if(dnames.equals("EC"))
		System.out.println(dnames);
		else
		System.out.println("No EC");
		}
		int[] test = new int[] {1,4,5,7};	

		int[] test1={5,4,3,2,1};
		System.out.println(test1.length);
	}
}