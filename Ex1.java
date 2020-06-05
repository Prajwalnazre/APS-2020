interface IFace10
{
void printObject(IFace10 iface10);
}
class Ex1 implements IFace10
{
	int x;
	Ex1(){}
	Ex1(int x){this.x=x;}
	public void printObject(IFace10 iface10)
	{
	System.out.println(iface10);
	}
	public String toString()
	{
	return "object="+x;
	}
	public static void main(String[] args)
	{
		Ex1 obj=new Ex1(10);
		System.out.println(obj);
	}
}