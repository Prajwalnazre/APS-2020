class myException extends Exception{
	public myException(String str) {
		super(str);
	}
}

class date{
	int day,month,year;
	date() {}
	date(int day,int month,int year) throws myException {
		this.day = day;
		this.month = month;
		this.year = year;
		if(day > 31) {
			throw new myException("Invalid Date");
		}
		if(month > 12) {
			throw new myException("Invalid Month");
		}
		
	}
	
	public void printDate(){
		System.out.println(day + "-" + month + "-" + year);
	}
	
}

public class CurrentDate {
	public static void main(String[] args) {
		try {
			date d = new date(32,06,1999);
			d.printDate();
		}
		
		catch(myException ex)
		{
			System.out.println(ex.getMessage());
		}
	}

}
