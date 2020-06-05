
import java.util.*;

//Scanner Demo
class ScannerDemo{
	public static void main(String[] args)
	{
	Scanner s=new Scanner(System.in);
	System.out.println("Enter int data");
	int intData=s.nextInt();
	System.out.println("Int:"+intData);
	System.out.println("Enter float data");
	float floatData=s.nextFloat();
	System.out.println("float:"+floatData);
	System.out.println("Enter double data");
	double doubleData=s.nextDouble();
	System.out.println("double:"+doubleData);
	System.out.println("Enter string data");
	int stringData=s.next();
	System.out.println("string"+stringData);
	

	}	
	

}	

/*class ArrayDemo4
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
	for(int i=0;i<3;i++)
	{
	for(int j=0;j<3;j++)
	{
		System.out.println(twoD[i][j]);
	}
	}
	
	}
}*/