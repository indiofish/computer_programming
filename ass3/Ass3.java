import java.util.Arrays;
public class Ass3
{
  private static class MyInt
  {
    int num;

    public MyInt()
    {//default
      num = 0;
    }

    public MyInt(int n)
    {
      num = n;
    }

    @Override
    public boolean equals(Object obj) 
    {
      if (this == obj) {
        return true;
      }
      if (obj == null) {
        return false;
      }
      if (!(obj instanceof MyInt)) {
        return false;
      }
      MyInt other = (MyInt) obj;
      if (num != other.num) {
        return false;
      }
      return true;
    }

  }

  
  public static void main (String[] args) 
  {
    MyInt[] a1, a2;
    int length = 10;
    a1 = new MyInt[length];
    a2 = new MyInt[length];

    for (int i = 0; i < length; i++) {
      a1[i] = new MyInt(i);
      a2[i] = new MyInt(i);
    }
    System.out.println(Arrays.equals(a1,a2));

    return;
  }

}
