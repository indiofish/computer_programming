import java.util.*;
import java.util.Iterator;

public class IteratorEx {

  public static void main (String[] args) {
    ArrayList a = new ArrayList();
    a.add(1);
    a.add("comp");
    a.add(2.0);
    Iterator i = a.iterator();
    while(i.hasNext()) {
      Object obj = i.next();
      if(obj instanceof String) {
        String str = (String)obj;
        System.out.println(str + " is string");
      }
      else if(obj instanceof Integer) {
        int n = (Integer)obj;
        System.out.println(n);
      }
      else if(obj instanceof Double) {
        double d = (Double)obj;
        System.out.println(d);
      }

    }


  }
}
