/*
A general example to demonstrate the following:
copy constructor
A method returning object
object as a parameter for method
Method returning array of objects
Array of objects as a parameter for method
*/

import java.util.*;

class A{
	int x;
	int y;
	A(){
	x=0;	
	y=0;
	}
	A(int x, int y){
	this.x=x;
	this.y=y;

	}
	A(A obj){
	this.x=obj.x;
	this.y=obj.y;
	}
	public String toString(){
	return x+":"+y;
	}
	//function returning object
	
	A getA(){
	return new A(10,20);
	}

	//object as parameter for function

	void modifyObject(A obj)
	{
	
	Scanner sc=new Scanner(System.in);
	System.out.println("Enter values to update x and y");
	int a=sc.nextInt();
	int b=sc.nextInt();
	obj.x+=a;
	obj.y+=b;
	}
	
	A[] getObjects(){
	
	System.out.println("Enter number of objects to create");
	Scanner sc1=new Scanner(System.in);
	
	int count=sc1.nextInt();

	A[] objects=new A[count];
	
	for(int i=0;i<objects.length;i++){
		
		objects[i]=new A();
		objects[i].x=sc1.nextInt();
		objects[i].y=sc1.nextInt();
	
	}
	return objects;
	
	
	}

	// print array of objects
	void printObjects(A[] objects){
	
	for(int j=0;j<objects.length;j++){
	System.out.println(objects[j]);
	}

	}
		
}
class ADemo{
	public static void main(String[] args){
	A obj=new A();
	A obj1=new A(1,2);
	A obj2=new A(obj1);

	System.out.println(obj);
	System.out.println(obj1);
	System.out.println(obj2);

	A obj3=obj.getA();

	System.out.println(obj3);	
	obj.modifyObject(obj3);
	System.out.println(obj3);

	// get array of objects
	
	A[] myObjects=obj.getObjects();

	// print array of objects

	obj.printObjects(myObjects);	
	
	}

}