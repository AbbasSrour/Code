package hwPr1;

import java.util.Scanner;

public class App {

  public static void main(String[] args) {
    // Setting up the variables needed
    Scanner scanner = new Scanner(System.in);
    char a; // the grade
    int classCount = 0; // number of students in the class
    int failCount = 0; // number of students who get "F"

    // the loop will start by asking the user to enter the first value before
    // chechking, it allows the program to be shorter
    do {
      System.out.print("Enter a a letter Grade: ");
      a = scanner.next().charAt(0);
      if (a == 'A' || a == 'B' || a == 'C' || a == 'D' || a == 'F')
        classCount++; // increaments the counter for every accepted value
      if (a == 'F') // increaments the counter every time 'F' is entered
        failCount++;
    } while (Character.isLetter(a) == true);

    // calculating the percentage of failed students and printing it out
    double percentage = (failCount * 100) / (double) classCount;
    System.out.println("The percentage of failed students is " + percentage);

    scanner.close();
  }
}
