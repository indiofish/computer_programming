import java.util.Scanner;
import java.util.Arrays;

public class FindMax {
  public static void main (String[] args) {
    Scanner in = new Scanner(System.in);
    int intArray[] = new int[5];
    int length = intArray.length;
    int max = -1000000;

    for (int i = 0; i < length; i++) {
      intArray[i] = in.nextInt();
    } 

    for (int i = 0; i < length; i++) {
      if (intArray[i] > max)
        max = intArray[i];
    }
    System.out.println("max: " + max);
  }
}
