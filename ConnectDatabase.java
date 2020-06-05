package studentdatabase;
import studentdatabase.*; 

import java.io.EOFException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Scanner;

public class ConnectDatabase {
	
	protected Connection con;

	public ConnectDatabase() {
		try {
			Class.forName("com.mysql.jdbc.Driver");
		} catch (ClassNotFoundException e){
			e.printStackTrace();
		}
		try {
			con=DriverManager.getConnection("jdbc:mysql://localhost:3306/ssce","root","");
		} catch (SQLException e) {
			e.printStackTrace();
		}  
	}
	public void closeconnection()
	{
		try {
			con.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	public void newStudent(Student stud)
	{
		PreparedStatement pr;
		int c;
		try {
			pr = con.prepareStatement("insert into student values(?,?,?)");
			pr.setInt(1,stud.getRollno());
			pr.setString(2,stud.getName());
			pr.setFloat(3,stud.getDepID());
			c=pr.executeUpdate();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
		public void updateStudent(Student stud)
		{
			PreparedStatement pr;
			int c;
			try {
				pr = con.prepareStatement("update student set name=?,per=? where rollno=?");
				pr.setInt(3,stud.getRollno());
				pr.setString(1,stud.getName());
				pr.setFloat(2,stud.getDepID());
				c=pr.executeUpdate();
			} catch (SQLException e) {
				e.printStackTrace();
			}	
		}
		public void deleteStudent(int rollno)
		{
			PreparedStatement pr;
			int c;
			try {
				pr = con.prepareStatement("delete from student where rollno=?");
				pr.setInt(1,rollno);
				//pr.setString(1,stud.getName());
				//pr.setFloat(2,stud.getPer());
				c=pr.executeUpdate();
			} catch (SQLException e) {
				e.printStackTrace();
			}	
		}
		public void insertMarks(int data,Student Stud)
		{
			int c;
			PreparedStatement pr;
			try {
				if(Stud.rollno==data)
				{
					//Stud.AddCourse(101);
					//Stud.AddCourse(103);
					for(int i=0;i<Stud.StudCourse.length;i++)
					{
				pr = con.prepareStatement("insert into exammarks values(?,?,?,?,?,?,?,?,?)");
				pr.setInt(1,Stud.getRollno());
				pr.setInt(2,Stud.StudCourse[i].getCourseID());
				pr.setInt(3,Stud.getISAMark1());
				pr.setInt(4,Stud.getISAMark2());
				pr.setInt(5, Stud.getESAMark1());
				pr.setInt(6, Stud.getESAMark2());
				
				c=pr.executeUpdate();
				}
				}
			} catch (SQLException e) {
				e.printStackTrace();
			}	
			
		}
		public ArrayList<Student> selectStudent()
		{
			Statement pr;
			ResultSet c;
			Student s;
			ArrayList<Student> list=new ArrayList<Student>(); 
			try {
				pr = con.createStatement();
				c=pr.executeQuery("select * from student");
				while(c.next())
				{
					 s=new Student(c.getInt(1),c.getString(2),c.getInt(3));
					 list.add(s);
				}
				c.close();
				
		
			} catch (SQLException e) {
				e.printStackTrace();
			}return list;	
		}
		
		public static void main(String[] args)
		{
			ConnectDatabase c;
			Scanner scan=new Scanner(System.in);
			c= new ConnectDatabase();
			int ch,rol;
			ArrayList<Student> list;
			do{
				System.out.println("1.insert data\n2.delete data\n3.update data\n4.fetch data\n");
				ch=scan.nextInt();
				switch(ch)
				{
				case 1:Student stud=new Student(scan.nextInt(),scan.next(),scan.nextInt());
				//c.newStudent(stud);
				//stud.AddCourse(101);
				break;
				case 5:
					GetCourse g=new GetCourse();
					g.getCourse(108);
					AllCourse a1=g.getNew1();
					g.getCourse(107);
					AllCourse a2=g.getNew1();
				Student stud1=new Student(1001,"45632",3,a1,a2);
				
				
				//stud1.AddCourse(g.getNew1());
				//stud1.AddCourse(101);
				stud1.setISAMark1(25);
				stud1.setISAMark2(25);
				stud1.setESAMark1(25);
				stud1.setESAMark2(25);
				//System.out.println(g.getNew1());
				stud1.GetDetailsStudent();
				stud1.StudentDetails();
				
				//c.insertMarks(1001, stud1);
				break;
				case 2:rol=scan.nextInt();
					c.deleteStudent(rol);
				break;
				case 3:Student stud2=new Student(scan.nextInt(),scan.next(),scan.nextInt());
				c.updateStudent(stud2);
				break;
				case 4:list=c.selectStudent();
				for (Student data:list)
					System.out.println(data);
				break;
				}
			}while(ch!=5);
			
			
		}
	}
	
	


