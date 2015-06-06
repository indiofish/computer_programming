import java.util.ArrayList;
import java.io.*;
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
    {//push the object to stack, and increase count,size will be automatically managed
      stack.add(count,obj);
      count++;
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


    //unnecessary
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
    //remove spaces
    test = test.replaceAll("\\s+","");

    try (Writer writer = new BufferedWriter(new OutputStreamWriter(
            new FileOutputStream("stack.txt"), "utf-8"))) 
    {
      for (int i = 0; i < test.length(); i++) {
        if (test.charAt(i) == '+') {
          //if +, read the next char to add
          i++;
          writer.write("[push] "+ test.charAt(i)+"\n");
          stk.push(test.charAt(i));
        } 
        else if (test.charAt(i) == '-') {
          try {
            writer.write("[pop] " + stk.pop()+"\n");
          } catch(IndexOutOfBoundsException e) {
            System.out.println("Stack out of bounds" + e.toString());
          }
        }
      }
      writer.write(stk.toString());
    }catch (IOException ex) {
      System.out.println("Unable to Write to File");
    } 
  }
}
