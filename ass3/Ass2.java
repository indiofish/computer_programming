import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.*;
public class Ass2 
{
  final static String input = 
    "+ C + o + m + p + u + t + e - + r - + P + r + o + g - + r + a + m + 1 + 5";
  //TODO add error catching.
  private static class MyStack<T>
  {
    private ArrayList<T> stack;
    private int count;

    public MyStack(int initSize)
    {
      stack = new ArrayList<>(initSize);
      count = 0;
    }

    public void push(T obj)
    {//push the object to stack, and increase count,size will be automatically managed
      stack.add(count,obj);
      count++;
    }

    public T pop() throws IndexOutOfBoundsException 
    {//pops the top object which is managed by count, decrease 1
      T item = null;
      //-1 from count because ArrayList index starts from 0
      count--;
      try {
        item = stack.remove(count);
      } catch(IndexOutOfBoundsException e) {
        System.out.println("Stack is already empty: " + e.toString());
      }
      return item;
    }

    public T peek() throws IndexOutOfBoundsException 
    {//doesn't pop
      T item = null;
      try {
        //temporary -1 from count because ArrayList index starts from 0
        item = stack.get(count-1);
      } catch(IndexOutOfBoundsException e) {
        System.out.println("Stack is already empty: " + e.toString());
      }
      return item;
    }

    public void clear()
    {
      stack.clear();
    }

    public int size()
    {
      return count;
    }

    @Override
    public String toString()
    {
      String result = "";
      for (int i = 0; i < count; i++) {
        result += stack.get(i);
      }
      return result;
    }

  }

  public static void main (String[] args) 
  {
    MyStack<Character> stk = new MyStack<>(100);
    String token = "";
    //space becomes the token for default
    StringTokenizer tk = new StringTokenizer(input);

    try (Writer writer = new BufferedWriter(new OutputStreamWriter(
            new FileOutputStream("stack.txt"), "utf-8"))) 
    {
      while(tk.hasMoreTokens()) {
        token = tk.nextToken();
        if (token.charAt(0) == '+') {
          //if +, read the next char to add
          stk.push(tk.nextToken().charAt(0));
          writer.write("[push] "+ stk.peek() + '\n');
        } 
        else if (token.charAt(0) == '-') {
          writer.write("[pop] " + stk.pop()+"\n");
        }
      }
      writer.write(stk.toString());
      //writer.close();
    }catch (IOException ex) {
      System.out.println("Unable to Write to File");
    }     
    return;
  }

}
