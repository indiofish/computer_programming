import java.lang.*;
import java.util.List;
import java.util.ArrayList;
public class Fibonacci
{
  public static class FibonacciSeq
  {
    List<Integer> fibonacci; 

    public FibonacciSeq()
    {
      fibonacci = new ArrayList<>(0);
    }

    public FibonacciSeq(int len)
    {
      fibonacci = new ArrayList<>(len);
      for (int i = 0; i < len; i++) {
        getNext();
      }
    }

    public void setLength(int newLen) 
    {//similar to get but changes array
      int length = this.getLength();

      for (int i = 0; i < newLen - length; i++) {
        this.getNext();
      }
      fibonacci = fibonacci.subList(0,newLen);

      return;
    }

    public int getNext()
    {//append to the sequence
      int length = this.getLength();

      if (length <= 1) {
        fibonacci.add(1);
      }
      else {
        fibonacci.add(fibonacci.get(length-1) + fibonacci.get(length-2));
      }
      length++;
      return fibonacci.get(length-1);
    }

    public int getLength()
    {
      return fibonacci.size();
    }


    public int get(int index) throws IndexOutOfBoundsException
    {//if index > length calculate to get value(but doesn't change the array)
      int result = 0;
      int a, tmp = 0;
      int length = this.getLength();

      //if index <= length just bring the value instead of calculation.
      if (index <= length) {
        try {
          result = fibonacci.get(index-1);
        } catch(IndexOutOfBoundsException e) {
          System.out.println("ERROR: " + e.toString());
        }
      } 
      else {
        //result is last number of the sequence
        a = fibonacci.get(length-2);
        result = fibonacci.get(length-1);

        for (int i = 0; i < index - length; i++) {
          //hold a's value to add to result;
          tmp = a;
          //previous number is updated to the last number
          a = result;
          //next number(result) is last number of sequence + previous number
          result += tmp;
        } 
      }
      return result;
    }

    @Override
    public String toString()
    {
      String fibo = fibonacci.toString();
      //remove start and end brackets([, ])
      return fibo.substring(1,fibo.length()-1);
    }

  }

  public static void main (String[] args) {
    int length = Integer.parseInt(args[0]);
    FibonacciSeq fib = new FibonacciSeq(length);
    System.out.println(fib);
    //System.out.println(fib.get(15));
    //System.out.println(fib);
    //fib.setLength(11);
    //System.out.println(fib);
    //System.out.println(fib.get(10));
  }
}
