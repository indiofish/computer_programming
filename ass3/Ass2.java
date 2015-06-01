//TODO write to a file.
public class Ass2 
{
  public static void main (String[] args) {
    MyStack<Character> stk = new MyStack<>(100);
    String test = "+T+E-+S+t+a+t+l-";

    for (int i = 0; i < test.length(); i++) {
      if (test.charAt(i) == '+') {
        i++;
        System.out.print("[push] ");
        System.out.println(test.charAt(i));
        stk.push(test.charAt(i));
      } 
      else if (test.charAt(i) == '-') {
        System.out.print("[pop] ");
        System.out.println(stk.pop());
      }
    }

    stk.printAll();
  }
}
