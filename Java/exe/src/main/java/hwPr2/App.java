package hwPr2;

import java.util.Scanner;

public class App {
  public static void main(String[] args) {
    // setting up the scanner and the variable needed to preform the operation
    int positiveInt = 0;
    int sum = 0;
    Scanner scanner = new Scanner(System.in);

    // Asking for the user to enter a value
    // an exception should be thrown if the user enters a non integer value
    System.out.print("Please enter a positive integer value strictly less than 2147483000: ");
    positiveInt = scanner.nextInt();

    // place holder
    int aux = positiveInt;

    if (positiveInt > 0 && positiveInt <= 2147483000) { // if the value is <= 2147483000 we will preform the operation
      while (aux > 0) { // A while loop to get the sum of the digits
        sum += aux % 10;
        aux /= 10;
      }
      if (sum % 2 == 0) // if the sum % 2 returns 0 then sum is even
        System.out.println("Sum of digits of " + positiveInt + " is: " + sum + "; Even.");
      else // it didn't return 0 so it's not even
        System.out.println("Sum of digits of " + positiveInt + " is: " + sum + "; Odd.");
    } else if (positiveInt > 2147483000) { // in case the user enters a number bigger than the allowed value
      System.out.println("Number entered is greater than 2147483000");
    } else if (positiveInt <= 0) { // in case the user enters a negative or zero number
      System.out.println("Number entered is not a positive integer");
    }

    scanner.close();
  }
}
