import java.io.*;
import java.net.*;

public class SocketClient {
  public static void main (String[] args) {

    OutputStreamWriter osw=null;

    try {
      osw=new OutputStreamWriter(new
          Socket("127.0.0.1",5777).getOutputStream());
    } catch (IOException e) {
      System.out.println("Fail");
      System.exit(-1);
    }
    String str = "comp";

    try {
      osw.write(str,0,4);
      osw.flush();
    } catch (IOException e) {
      System.out.println("fail.");
    }
    try {
      osw.close();
    } catch (IOException e) {
      System.out.println("close fail");
    }

  }
}
