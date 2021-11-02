package array;

import java.util.Scanner;

public class App {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n, m;
    System.out.print("Please enter the number of rows: ");
    n = scanner.nextInt();
    System.out.print("Please enter the number of columns: ");
    m = scanner.nextInt();

    int array[][] = new int[n][m];

    for (int i = 0; i < array.length; i++) {
      for (int j = 0; j < array[i].length; j++) {
        array[i][j] = i * j;
      }
    }

    System.out.println("The values of the array are: ");
    for (int i = 0; i < array.length; i++) {
      for (int j = 0; j < array[i].length; j++) {
        System.out.println("The value of row " + i + " column " + j + " is equal to " + array[i][j]);
      }
    }

    scanner.close();
  }
}
