class A
{
	public interface NestedFace
	{
	void printMe();
	}
void printU(String str)
{
	System.out.println(str);
}
}
class ADemo
{
	public static void main(String[] args)
	{
	A obj =new A();
	obj.printU("printing U");
	}
}
