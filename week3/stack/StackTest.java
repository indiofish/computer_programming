interface StackInterface
{
  void make_empty();
  boolean is_empty();
  void push(Object x);
  Object pop();
}

class Node
{
  Object data;
  Node next;
}

class Stack implements StackInterface
{
  private Node top;

  public void make_empty()
  {
    while (!is_empty()) pop();
    top = null;
  }

  public boolean is_empty()
  {
    //return top == null (?);  
    if (top == null)
      return true;
    else
      return false;
  }

  public void push(Object i)
  {
    Node new_node = new Node();
    if (new_node == null) {
      System.out.println("Error in push: stack is full");
    }

    new_node.data = i;
    new_node.next = top;
    top = new_node;
  }

  public Object pop()
  {
    Node old_top;
    Object i;
    if (is_empty()) {
      System.out.println("Error in pop: stack is empty");
    }

    old_top = top;
    i = top.data;
    top = top.next;

    return i;
  }

}

public class StackTest
{
  public static void main (String[] args) {
    int i = 3;
    char j = 'S';
    double k = 12.0;
    Stack s = new Stack();
    s.make_empty();
    s.push(new Integer(i));
    s.push(new Character(j));
    s.push(new Double(k));

    System.out.println("POP : " + s.pop());
  }
}

