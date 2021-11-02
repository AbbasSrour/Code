package append;

import java.util.Scanner;

public class App {

  public static void fill(int array[]) {
    Scanner scanner = new Scanner(System.in);
    for (int i = 0; i < array.length; i++) {
      System.out.print("Please enter the element of index " + i + " : ");
      array[i] = scanner.nextInt();
    }
    scanner.close();
  }

  public static void printArr(int array[]) {
    for (int i = 0; i < array.length; i++) {
      System.out.println("The element of index " + i + "is equal to " + array[i]);

    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("please enter the number of elements: ");
    int n = scanner.nextInt();
    int arr[] = new int[n];
    fill(arr);

    scanner.close();
  }

}
