abstract class Employee
{

abstract Manager[] getManagers();

}
class Manager extends Employee
{
	Manager[] getManagers()
	{
	Manager[] temp=new Manager[2];
	temp[0]=new Manager();
	temp[1]=new Manager();

	return temp;
	}
}
