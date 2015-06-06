//TODO write to a file.
import java.util.ArrayList;
public class Ass2 
{
  //TODO add error catching.
  private static class MyStack<T>
  {
    private ArrayList<T> stack;
    private int count;
    private int maxSize;

    public MyStack(int initSize)
    {
      maxSize = initSize;
      stack = new ArrayList<>(maxSize);
      count = 0;
    }

    public void push(T obj)
    {//push the object to stack, and increase count
      stack.add(count,obj);
      count++;
      //unnecessary?
      //incSize();
    }

    public T pop() //throws Exception 
    {//pops the top object which is managed by count, decrease 1
      count--;
      return stack.remove(count);
    }

    public T peek()
    {//doesn't pop
      return stack.get(count-1);
    }

    public void clear()
    {
      stack.clear();
    }

    public int size()
    {
      return count;
    }

    public int maxSize()
    {
      return maxSize;
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

    public void printAll()
    {
      for (int i = 0; i < count; i++) {
        System.out.print(stack.get(i));
      }
      System.out.println();
      return;
    }


    private void incSize()
    {//if stack is full, increase size by double.
      if (count >= maxSize) {
        System.out.println("current size is" + maxSize);
        maxSize *= 2;
        stack.ensureCapacity(maxSize);
        System.out.println("new size is" + maxSize);
      }
    }

  }
   
  public static void main (String[] args) 
  {
    MyStack<Character> stk = new MyStack<>(100);
    String test="+ C + o + m + p + u + t + e - + r - + P + r + o + g - + r + a + m + 1 + 5";
    test = test.replaceAll("\\s+","");

    //TODO print this to file
    for (int i = 0; i < test.length(); i++) {
      if (test.charAt(i) == '+') {
        //if +, read the next char to add
        i++;
        System.out.print("[push] ");
        System.out.println(test.charAt(i));
        stk.push(test.charAt(i));
      } 
      else if (test.charAt(i) == '-') {
        System.out.print("[pop] ");
        try {
          System.out.println(stk.pop());
        } catch(IndexOutOfBoundsException e) {
          System.out.println("Illegal request of item: " + e.toString());
        }
      }
    }
    System.out.println(stk);
  }
}
