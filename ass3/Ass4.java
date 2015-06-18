import java.util.*;

public class Ass4 {
  final static String VOWEL = "aeiou";

  public static void main (String[] args) 
  {
    char c;
    Random rand = new Random();	//generate random instance

    //+1 to make 'z' inclusive //'a' ~ 'z'
    c = (char) (rand.nextInt('z' - 'a' + 1) + (int)'a');

    System.out.print(c + " is a ");
    //if char c is included in the String VOWEL
    System.out.println(VOWEL.contains(Character.toString(c)) ? "vowel." : "consonant.");
  }
}
