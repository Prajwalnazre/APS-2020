/*class Sample1{
	public static void main(String[] args){
		System.out.println("Hello World!");
		}
}*/

//Reading input from console

/*
class Sample1
{
	public static void main(String[] args){
	
	for(int i=0;i<args.length; i++){

	System.out.print(args[i]);
		
	//System.out.println(args[i]);
	}
	
	}
}*/
//Write a java program to read two integer numbers, add them and print the sum

class Sample1
{
	public static void main(String[] args){
	
	
	//System.out.print(args[i]);
		
	//System.out.println(args[i]);

	
	//for-each: variant of for loop
	/*
	for(String s:args){
	System.out.println(s);
	}
	*/
	int num1=Integer.parseInt(args[0]);
	int num2=Integer.parseInt(args[1]);
	
	int sum=num1+num2;
	
	System.out.println("sum="+sum);
		
	}
}

