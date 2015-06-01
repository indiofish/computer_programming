import java.util.*;

public class Ass4 {
  final static String VOWEL = "aeiou";

  public static void main (String[] args) 
  {
    char c;
    Random rand = new Random();	//generate random instance

    //to make 'z' inclusive
    //'a' ~ 'z'
    c = (char) (rand.nextInt('z' - 'a' + 1) + (int)'a');

    //if char c is included in the String vowel
    if (VOWEL.indexOf(c) != -1)
      System.out.println(c + " is a vowel.");
    else
      System.out.println(c + " is a consonant.");
  }
}
