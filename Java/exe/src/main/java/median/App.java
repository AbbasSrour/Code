package median;

import java.util.Scanner;

public class App {

  public static void sort(int array[]) {
    int aux;
    int n = array.length;

    for (int j = 0; j < (n - 1); j++) {
      for (int i = 0; i < (n - j - 1); i++) {
        if (array[i] > array[i + 1]) {
          aux = array[i];
          array[i] = array[i + 1];
          array[i + 1] = aux;
        }
      }
    }
  }

  public static int median(int array[]) {
    int median;
    int n = array.length;

    if (n % 2 == 0)
      median = array[(n / 2) + 1];
    else
      median = array[(n / 2)];

    return median;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n;
    System.out.print("Please enter the number of elements: ");
    n = scanner.nextInt();

    int arr[] = new int[n];

    for (int i = 0; i < n; i++) {
      System.out.print("Please enter the variable of index " + i + " : ");
      arr[i] = scanner.nextInt();
    }

    sort(arr);

    for (int i = 0; i < n; i++) {
      System.out.println("The value of element " + i + " is equal to : " + arr[i]);
    }

    int median = median(arr);
    System.out.println("The value of the median is : " + median);

    scanner.close();
  }
}
