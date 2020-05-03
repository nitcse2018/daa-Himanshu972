package lab;
import java.io.*;

public class char_byte 
{
	public static void main(String[] args)throws IOException 
	{
		FileReader f_in = null;
		FileOutputStream f_out = null;
		
		try
		{
			f_in = new FileReader("C:/Users/Himanshu Srivastava/Desktop/Java/IO programming/Youtube/source2.text");
			f_out = new FileOutputStream("C:/Users/Himanshu Srivastava/Desktop/Java/IO programming/Youtube/target2.text",true); 
			
			int temp;
			while( (temp = f_in.read())!= -1 )
				f_out.write( (byte)temp );
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
