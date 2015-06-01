public class Dog 
{
  public static void bark()
  {
    System.out.println("Bow Wow!");
  }

  public static void bark(int n)
  {
    for (int i = 0; i < n; i++) {
      System.out.println("Bow Wow!");
    }
  }

  public static void bark(String s) 
  {
    System.out.println("Grr... " + s + "..!");
  }

  public static void bark(char c) 
  {
    System.out.print("G");
    for (int i = 0; i < 8; i++) {
      System.out.print(c);
    }
    System.out.println("!");
  }

  public static void main (String[] args) {
    Dog.bark(3);
    Dog.bark("FXXK You");
    Dog.bark('F');
  }
}
