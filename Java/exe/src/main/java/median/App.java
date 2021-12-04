package median;

import java.util.Scanner;
import java.lang.Math;

public class App{

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter the reservoir’s radius and height in centimeters:");
    int radius= scanner.nextInt();
    int height= scanner.nextInt();

    double volume = 3.14 * radius *radius * height;
    double Mvolume = volume/100;
    int Lvolume = (int) volume/10;

    System.out.println("The volume of the reservoir is " + Mvolume + " meters cube, which is" + Lvolume + "liters.");


    scanner.close();
  }

}
