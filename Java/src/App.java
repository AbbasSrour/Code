import java.util.Scanner;

public class App{
  public static void main(String[] args) {
   System.out.println("Hello World");
   int a = 5;
   char b = 'h';
   String h = "hello World\n";
   System.out.println(a+b);
   System.out.print(h); 
   System.out.println(h.charAt(0));
   int array [][][] = new int [10][10][10];
   array[0][0][0]= 1;
   System.out.println(array[0][0][0]);

   Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    scanner.close();
    System.out.print(n);
  }
}
