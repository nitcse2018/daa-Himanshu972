package lab;
import java.io.*;

public class byte_char 
{
	public static void main(String[] args)throws IOException 
	{
		FileInputStream f_in = null;
		FileWriter f_out = null;
		
		try
		{
			f_in = new FileInputStream("C:/Users/Himanshu Srivastava/Desktop/Java/IO programming/Youtube/source1.text");
			f_out = new FileWriter("C:/Users/Himanshu Srivastava/Desktop/Java/IO programming/Youtube/target1.text",true); 
			
			int temp;
			while( (temp = f_in.read())!= -1 )
				f_out.write( (char)temp );
		}
		finally
		{
			if(f_in != null)
				f_in.close();
			if(f_out != null)
				f_out.close();
		}
	}
}
