import java.lang.*;
public class Fibonacci 
{
  private static String fiboGen(int num)
  {//return String of Fibonacci sequence
    int[] fb = {1,1,0};
    long a1 = 1;
    long a2 = 1;
    long lastNum = 0;
    String result = "";

    if (num == 1)
      result = "1";

    else if (num == 2)
      result = "1,1";

    else if (num>=3) {
      result = "1,1";
      for (int i = 0; i < num - 2; i++) {
        result += ",";
        lastNum = (a1+a2);
        a1 = a2;
        a2 = lastNum;
        result += lastNum;
      }
    }
    else 
      result = "Number Out Of Bounds";

    return result;
  }



  public static void main (String[] args) {
    System.out.println(fiboGen(Integer.parseInt(args[0])));
  }
}
