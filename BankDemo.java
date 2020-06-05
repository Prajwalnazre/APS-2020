class BankAccount
{
 int accNo;
double balance=0;
String accType;
BankAccount(){}
BankAccount(int accNo, double balance, 
String accType)
{
	this.accNo=accNo;
	this.balance=balance;
	this.accType=accType;
}
}
class Customer
{
	int custId;
	String custName;
	BankAccount[] bankAccounts;
	Customer(){}
	Customer(int custId, String custName)
	{
	this.custId=custId;
	this.custName=custName;
	bankAccounts=new BankAccount[2];
	bankAccounts[0]=new BankAccount(12345,500,"SB");
	bankAccounts[1]=new BankAccount(23456,500,"CA");
	}
	/*
	void openAccounts()
	{
	
	// Assumption bank account array is created in constructor
	bankAccounts[0]=new BankAccount(12345,500,"SB"); 
	bankAccounts[1]=new BankAccount(23456,500,"CA");
	}
	*/
	void depositAmt(BankAccount ba,double amt)
	{
		ba.balance+=amt;
	}
	void withdrawAmt(BankAccount ba, double amt)
	{
	if(ba.balance<500)
	System.out.println("Cannot withdraw");
	else if(ba.balance - amt<500)
System.out.println("Cannot withdraw maintain min balance");
	else
	ba.balance-=amt;
	}
	// assumption ba1 is SB account
	void transferAmt(BankAccount ba1, BankAccount ba2, double amt)
	{	ba1.balance-=amt;
		ba2.balance+=amt;
	}
	void payInterest(BankAccount ba)
	{
	if(ba.accType.equals("SB"))
	{
	ba.balance=ba.balance+(ba.balance*0.04);
	}
	else
	{System.out.println("Interest cannot be paid for CA");
	}		
	}
}
class BankDemo
{
	public static void main(String[] args)
	{
	Customer customer=new Customer(1111,"aaa");
	System.out.println(customer.bankAccounts[0].accNo);
	System.out.println(customer.bankAccounts[0].balance);
	customer.depositAmt(customer.bankAccounts[0],1000);
	System.out.println(customer.bankAccounts[0].balance);
	customer.withdrawAmt(customer.bankAccounts[0],1000);
	System.out.println(customer.bankAccounts[0].balance);
	customer.withdrawAmt(customer.bankAccounts[0],1000);
	System.out.println(customer.bankAccounts[0].balance);
	}
}