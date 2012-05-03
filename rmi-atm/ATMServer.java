import java.rmi.Naming;
import java.rmi.server.UnicastRemoteObject;//********		
import java.rmi.RemoteException;

public class ATMServer extends UnicastRemoteObject implements ATM{
	public ATMServer() throws RemoteException
	{
		super();	
	}
	public String display()
	{
		System.out.println("Succesfully called display method");
		return "Jayesh Pawar";
	}
	public static void main(String args[])
	{
		try
		{
			ATMServer s = new ATMServer();
			//System.out.println("rmi://localhost:1099/ATM");
			Naming.rebind("ATM",s);
			System.out.println("bind successfully");
		}catch(Exception e)
		{
			System.out.println("ATM server Error "+e.getMessage());
		}
	}
}
