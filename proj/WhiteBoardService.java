import java.awt.Color;
import java.awt.Container;
import java.net.MalformedURLException;
import java.rmi.NotBoundException;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface WhiteBoardService extends Remote {
	public void add(Shape s,String entity) throws RemoteException;
	public void remoteAdd(Shape s)throws RemoteException;
	public void removeFrontShape(String entity) throws RemoteException;
	public void remoteRemoveFrontShape()throws RemoteException;
	public void removeAll(String entity) throws RemoteException;
	public void remoteRemoveAll()throws RemoteException;
	public void setClientService() throws RemoteException, MalformedURLException, NotBoundException;
}