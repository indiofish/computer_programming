import java.util.Scanner;

public class Grading {
  public static void main (String[] args) {
    char grade;
    Scanner a = new Scanner(System.in);
    int score;

    score = a.nextInt();

    if (score == 100)
      //case where score / 10 == 10 but should be given A, not 'A'-1
      grade = 'A';
    else if (score < 100 && score >= 60)
      grade = (char) ('A' + 9 - (score/10));
    else
      grade = 'F';
    //grading is done based on 10th digit of the score.
    System.out.println("결과: " + grade);
    return;
  }
}
