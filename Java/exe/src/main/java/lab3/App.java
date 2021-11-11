package lab3;

import java.util.Scanner;

public class App {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Please enter the string: ");
    String T = scanner.nextLine();

    System.out.print("Please enter the value of i : ");
    int i = scanner.nextInt();
    System.out.print("Please enter the value of j : ");
    int j = scanner.nextInt();

    String T1 = "";
    T1 = subreverse(T, i, j);
    System.out.println(T1);

    String T2 = "";
    T2 = reverse(T);
    System.out.println(T2);

    scanner.close();
  }

  public static String subreverse(String T, int i, int j) {
    char arr[] = T.toCharArray();
    char temp;
    String N = "";

    for (int counter1 = i, counter2 = j; counter1 < counter2; counter1++, counter2--) {
      temp = arr[counter1];
      arr[counter1] = arr[counter2];
      arr[counter2] = temp;
    }

    for (int counter = 0; counter < arr.length; counter++)
      N += arr[counter];
    return N;
  }

  public static String reverse(String T) {
    String N = "";
    N = subreverse(T, 0, T.length() - 1);
    return N;
  }

  public static void biggerWord(String T) {
    String arr[] = new String[20];
    String word = "";
    String letter = "";
    int i = 0;
    int counter = 0;
    while (i < T.length()) {
      letter += T.charAt(i);
      if (letter != " ")
        word += letter;
      else if (letter == " ") {
        arr[counter] = word;
        word = "";
        counter++;
      }
    }
  }
}
