import java.util.ArrayList;
//TODO add error catching.
public class MyStack<T>
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

  public T pop()
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
  public void printAll()
  {
    for (int i = 0; i < count; i++) {
      System.out.print(stack.get(i));
    }
    System.out.println();
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
