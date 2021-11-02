package lab2;

import java.util.Scanner;

public class App {
  public static void fillarray(int arr[][]) {
    Scanner scanner = new Scanner(System.in);

    for (int i = 0; i < arr.length; i++) {
      for (int j = 0; j < arr[i].length; j++) {
        System.out.print("Please enter the value of the element " + j + " in array " + i + ": ");
        arr[i][j] = scanner.nextInt();
      }
    }
    scanner.close();
  }

  public static int max(int arr[][]) {
    int maxnum = arr[0][0];
    for (int i = 0; i < arr.length; i++) {
      for (int j = 0; j < arr[i].length; j++) {
        if (maxnum < arr[i][j])
          maxnum = arr[i][j];
      }
    }
    return maxnum;
  }

  public static int rowSum(int arr[][], int x) {
    int sum = 0;
    for (int i = 0; i < arr[x].length; i++) {
      sum += arr[x][i];
    }
    return sum;
  }

  public static int colsum(int arr[][], int y) {
    int sum = 0;
    for (int i = 0; i < arr.length; i++) {
      if (arr[i].length > y)
        sum += arr[i][y];
    }
    return sum;
  }

  public static int[] allRowSum(int arr[][]) {
    int arrsum[] = new int[arr.length];
    int sum = 0;

    for (int i = 0; i < arr.length; i++) {
      for (int j = 0; j < arr[i].length; j++) {
        sum += arr[i][j];
      }
      arrsum[i] = sum;
      sum = 0;
    }
    return arrsum;
  }

  public static boolean isRowMagic(int arr[][]) {
    int arr2[] = allRowSum(arr);
    for (int i = 0; i < arr2.length; i++) {
      if (arr2[i] != arr2[i + 1])
        return false;
    }
    return true;
  }

  public static int[] allColumnSum(int[][] arr) {
    int arr2[] = new int[arr.length];
    for (int i = 0; i < arr.length; i++) {
      arr2[i] = colsum(arr, i);
    }
    return arr2;
  }

  public static boolean isColumnMagical(int[][] arr) {
    int arr2[] = allColumnSum(arr);
    for (int i = 0; i < arr2.length; i++) {
      if (arr2[i] != arr2[i + 1])
        return false;
    }
    return true;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Please enter the number of arrays : ");
    int n = scanner.nextInt();
    System.out.print("Please enter the number of elements in the arrays : ");
    int m = scanner.nextInt();

    int array[][] = new int[n][m];
    fillarray(array);

    int max = max(array);
    System.out.println("The maximum element in the 2d array is " + max);

    System.out.print("Please enter the row number : ");
    int x = scanner.nextInt();
    int rowx = rowSum(array, x);
    System.out.println("The sum of elements in row " + x + " is equal to " + rowx);

    scanner.close();
  }
}
