
import java.util.*;

class ArrayDemo4
{
	public static void main(String[] args)
	{
	int twoD[][]=new int[3][3];		
	Scanner s=new Scanner(System.in);
	System.out.println("Enter element values");
	for(int i=0;i<3;i++)
	{
	for(int j=0;j<3;j++)
	{
		twoD[i][j]=s.nextInt();
	}
	}
	System.out.println("Array elements entered are");
	for(int i=0;i<3;i++)
	{
	for(int j=0;j<3;j++)
	{
		System.out.print(twoD[i][j]+"\t");
	}
	System.out.println();
	}
	
	}
}



/*

A marketing company has 5 sales representatives and it maintains sales data 
quarterly. The company needs to find total sales of each sales representative
, maximum sales and minimum sales in each quarter, the maximum sales done by a 
representative in a year. Write a java program to implement the given scenario.

*/