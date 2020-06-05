/*
Customer{custId, custName,BankAccount, {methods: debitAccount(), 
creditAccount(),printAccount()}} 
has BankAccount{accNo, accBal, }
*/
























class BankAccount{
	int accNo;
	float accBal;

	BankAccount(){
	accNo=0;
	accBal=0;
	}
	BankAccount(int accNo, float accBal){
	this.accNo=accNo;
	this.accBal=accBal;
	}
	public String toString(){

	return this.accNo+":"+this.accBal;
	}
	void debitAccount(float amt){
	
	this.accBal-=amt;
	}
	void creditAccount(float amt){
	
	this.accBal+=amt;
	}
}
class Customer{
	int custId;
	String custName;
	BankAccount acc1;

	Customer(){}
	Customer(int custId, String custName, BankAccount acc){
	this.custId=custId;
	this.custName=custName;
	this.acc1=acc;
	}
	void creditAccount(float amt){
	acc1.creditAccount(amt);
	}
	void debitAccount(float amt){
	acc1.debitAccount(amt);
	}
	public String toString(){
	return custId+":"+custName+":"+acc1.toString();
	}
	
}

class BankAccountDemo{
	public static void main(String[] args){
	BankAccount account=new BankAccount(1001,1000);
	
	Customer customer=new Customer(1,"aaa",account);
	
	System.out.println(customer);	
	customer.creditAccount(100);
	customer.debitAccount(100);
	System.out.println(customer);	
	}

}