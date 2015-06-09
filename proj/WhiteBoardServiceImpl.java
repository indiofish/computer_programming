import java.awt.Container;
import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

@SuppressWarnings("serial")
public class WhiteBoardServiceImpl extends UnicastRemoteObject implements WhiteBoardService {


	public String entity;
	static WhiteBoardService server;
	static WhiteBoardService client;
	static ShapeContainer localShapeContainer; 
	
	public WhiteBoardServiceImpl(String e) throws RemoteException, MalformedURLException
	{
		entity = e;
		if(entity.equals("server"))
		{
			
			
		}
		else if(entity.equals("client"))
		{
			
			
		}
	}
	
	public static void main(String[] args) throws RemoteException, MalformedURLException, NotBoundException {
		if(args.length == 0)
		{
			System.out.println("you need arguments!");
			System.exit(0);
		}
		
		if(args[0].equals("client"))
		{
			WhiteBoardServiceImpl rmiModule = new WhiteBoardServiceImpl("client");
			
			if(args.length == 1)
			{
				System.out.println("type in server address!");
				System.exit(0);
			}
			
			System.out.println("Starting client....");
			
		    Naming.rebind("WhiteBoardClient", rmiModule);

		    String url = "rmi://" + args[1] + "/WhiteBoardServer";	
			server = (WhiteBoardService)Naming.lookup(url);
			server.setClientService();
			client = rmiModule;
			
			DrawingFrame frame = new DrawingFrame("client",client);
			localShapeContainer = (ShapeContainer) frame.getShapeContainer();
		
		}
		else if(args[0].equals("server"))
		{
			WhiteBoardService rmiModule = new WhiteBoardServiceImpl("server");

			System.out.println("Starting server....");
			
		    Registry reg = LocateRegistry.createRegistry(1099); 
		    Naming.rebind("WhiteBoardServer", rmiModule);
		    server = rmiModule;
			
		    DrawingFrame frame = new DrawingFrame("server",server);
			localShapeContainer = (ShapeContainer) frame.getShapeContainer();
		}
		else
		{
			System.out.println("wrong first argument!");
			System.exit(0);
		}
	}
	
	public void add(Shape s,String entity) throws RemoteException {
		if(entity.equals("server"))
		{
			localShapeContainer.add(s);
			client.remoteAdd(s);
			localShapeContainer.repaint();
		}
		else if(entity.equals("client"))
		{
			localShapeContainer.add(s);
			server.remoteAdd(s);
			localShapeContainer.repaint();
		}
    //System.out.println("ADDING STH");
	}
	
	public void remoteAdd(Shape s)throws RemoteException
	{
	
		localShapeContainer.add(s);
		localShapeContainer.repaint();
	}
	
	public void removeFrontShape(String entity) throws RemoteException
	{
		if(entity.equals("server"))
		{
			localShapeContainer.remove(localShapeContainer.getComponentCount()-1);
			client.remoteRemoveFrontShape();
			localShapeContainer.repaint();
		}
		else if(entity.equals("client"))
		{
			localShapeContainer.remove(localShapeContainer.getComponentCount()-1);
			server.remoteRemoveFrontShape();
			localShapeContainer.repaint();
		}
	}
	public void remoteRemoveFrontShape()throws RemoteException
	{
		localShapeContainer.remove(localShapeContainer.getComponentCount()-1);
		localShapeContainer.repaint();
	}
	
	public void removeAll(String entity) throws RemoteException
	{
		if(entity.equals("server"))
		{
			localShapeContainer.removeAll();
			client.remoteRemoveAll();
			localShapeContainer.repaint();
		}
		else if(entity.equals("client"))
		{
			localShapeContainer.removeAll();
			server.remoteRemoveAll();
			localShapeContainer.repaint();
		}
	}
	public void remoteRemoveAll()throws RemoteException
	{
		localShapeContainer.removeAll();
		localShapeContainer.repaint();
	}
	
	public void setClientService() throws RemoteException, MalformedURLException, NotBoundException
	{
		String url = "rmi://" + "localhost" + "/WhiteBoardClient";	
		client = (WhiteBoardService)Naming.lookup(url);
 
	}
}
