/* interface file extend from remote interfae */

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ATM extends Remote{
	String display() throws RemoteException;
}
