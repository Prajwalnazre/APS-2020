interface F1
{
	void display();

	interface F2	
	{
	void printMsg(String msg);
	}
}
 class NestedIF implements F1.F2
{
	public void printMsg(String msg)
	{
	System.out.println(msg);
	}
	public static void main(String[] args)
	{
	NestedIF nestedIf = new NestedIF();
	nestedIf.printMsg("Nested Interface");
	F1.F2 f1=nestedIf;
	f1.printMsg("Nested Interface");
	}
}