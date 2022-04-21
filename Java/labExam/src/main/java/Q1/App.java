package Q1;

import java.util.Scanner;

public class App {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Please enter the Restaurant name: ");
    String resName = scanner.nextLine();
    System.out.print("Please enter the Restaurant address: ");
    String resAddress = scanner.nextLine();
    System.out.print("Please enter the number of stars: ");
    int resStars = scanner.nextInt();
    System.out.print("Please enter the Restaurant speciality: ");
    scanner.nextLine();
    String resSpeciality = scanner.nextLine();
    System.out.print("Please enter the average dish price: ");
    double resAverageDishPrice = scanner.nextDouble();

    Restaurant userRestaurant =
        new Restaurant(resName, resAddress, resStars, resSpeciality, resAverageDishPrice);

    Restaurant myRestaurant = new Restaurant("Macdonalds", "Beirut", 3, "Burgers", 10);

    System.out.print("The Second Restaurant Speciality: ");
    System.out.println(myRestaurant.getSpeciality());
    userRestaurant.setStars(++resStars);

    System.out.println(userRestaurant);
    System.out.println(myRestaurant);
    scanner.close();
  }
}
