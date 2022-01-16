package pr1;

import java.util.Scanner;

public class App {
  public static char checkDivisible(int number) {
    if (number % 10 == 0) {
      return 'D';
    }
    return 'N';
  }

  public static int operate(char c, int number) {
    if (c == 'D') {
      return number * 15;
    }
    return number;
  }

  public static void main(String[] args) {
    int average = 0;
    System.out.println(" number          E/O          Operation");
    System.out.println();
    System.out.println(" --------------------------------------");

    int myArray[] = new int[13];

    for (int i = 0; i < 13; i++) {
      myArray[i] = 115 - (5 * i);
    }

    for (int i = 0; i < myArray.length; i++) {
      char c = checkDivisible(myArray[i]);
      // to make them look perfectly symetrical as all things should be
      if (myArray[i] >= 100)
        System.out.println(" " + myArray[i] + "             " + c + "             " + operate(c, myArray[i]));
      if (myArray[i] < 100)
        System.out.println(" " + myArray[i] + "              " + c + "             " + operate(c, myArray[i]));
      average += myArray[i];
    }
    average /= myArray.length;
    System.out.println(" The average is: " + average);
    Scanner scanner = new Scanner(System.in);
    scanner.close();
  }
}
