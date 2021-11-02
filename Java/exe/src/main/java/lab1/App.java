package lab1;

import java.util.Scanner;

public class App {

  public static void CumSum(int arr1[], int arr2[]) {
    int N = arr1.length;
    for (int i = 0; i < N; i++) {
      if (i == 0)
        arr2[i] = arr1[i];
      else
        arr2[i] = arr1[i] + arr2[i - 1];
    }

  }

  public static void fill(int arr[]) {
    Scanner scanner = new Scanner(System.in);
    int N = arr.length;
    for (int i = 0; i < N; i++) {
      System.out.print("Please enter the element of index " + i + " : ");
      arr[i] = scanner.nextInt();
    }
    scanner.close();
  }

  public static void printarr(int[] arr) {
    int N = arr.length;
    for (int i = 0; i < N; i++) {
      System.out.println("The element of index " + i + " in the Array  is equal to " + arr[i]);
    }
  }

  public static int MaxArray(int arr[]) {
    int N = arr.length;
    int max = arr[0];
    for (int i = 0; i < N; i++) {
      if (max < arr[i])
        max = arr[i];
    }
    return max;
  }

  public static int CheckElem(int arr[], int v) {
    int N = arr.length;
    for (int i = 0; i < N; i++) {
      if (arr[i] == v)
        return 1;
    }
    return 0;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Please enter the size of the array : ");
    int N = scanner.nextInt();
    int A[] = new int[N];
    int S[] = new int[N];

    fill(A);
    printarr(A);
    CumSum(A, S);
    printarr(S);

    int max = MaxArray(S);

    if (CheckElem(A, max) == 1)
      System.out.println("The Array is special");
    else if (CheckElem(A, max) == 0)
      System.out.println("The Array is special is not special");

    scanner.close();
  }
}
