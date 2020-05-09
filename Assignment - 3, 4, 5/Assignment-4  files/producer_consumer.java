package multithreadingg;
import java.util.*;
class Message
{
	private String message;
	private boolean isMessage;
	
	public synchronized void putMessage(String msg)        //  producer
	{
		while(isMessage == true)
			try { wait();} catch(Exception e){}
		
		isMessage = true;
		this.message = msg;
		try {Thread.sleep(500);} catch(Exception e) {}
		notify();
	}
	
	public synchronized String getMessage()                 //  consumer
	{
		while(isMessage == false)
			try { wait();} catch(Exception e){}
		
		isMessage = false;
		try {Thread.sleep(2000);} catch(Exception e) {}
		notify();
		return message;
	}
}

public class producer_consumer 
{
	public static void main(String[] args) throws Exception 
	{
		Scanner s = new Scanner(System.in);
		System.out.print(" How many messages do you want : ");
		int no = s.nextInt();
		System.out.println("");
		
		Message box = new Message();
		
		Thread producer = new Thread()
				{
					@Override
					public void run()
					{
						System.out.println(" Starting Producer thread ----> \n");
						for(int i=1;i<=no;i++)
						{
							String mess = "message no. " + i + " at time = " + System.nanoTime();
							box.putMessage(mess);
							System.out.println("	Producer thread has produced " + mess + "\n");
						}
					}
				};
		Thread consumer = new Thread()
				{
					@Override
					public void run()
					{
						System.out.println(" Starting Consumer thread ----> \n");
						for(int i=1;i<=no;i++)
						{
							System.out.println("		Consumer thread got the produced " + box.getMessage() + "\n");
						}
					}
				};
				
		
		try {Thread.sleep(1000);} catch(Exception e) {}
		producer.start();
		
		try {Thread.sleep(400);} catch(Exception e) {}
		consumer.start();
	}
}
