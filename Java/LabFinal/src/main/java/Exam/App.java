package Exam;

import java.util.ArrayList;
import java.util.Scanner;

public class App {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter the Agency Name:");
    String name = scanner.nextLine();
    System.out.println();

    Agency myAgency = new Agency(name);
    Apartment A = new Apartment(15000, "Beirut", 700.0, 5, true);
    Apartment B = new Apartment(10000, "Saida", 500.0, 3, false);
    Apartment C = new Apartment(12000, "Maten", 900.0, 12, true);
    Land D = new Land("Sour", 1000000, 2000.0, "Residential");
    Land E = new Land("Akkar", 1200000, 3000.0, "Agricultural");

    myAgency.addProperty(A);
    myAgency.addProperty(B);
    myAgency.addProperty(C);
    myAgency.addProperty(D);
    myAgency.addProperty(E);

    for (int i = 0; i < myAgency.getProperties().size(); i++) {
      if (myAgency.getProperties().get(i) instanceof Land && myAgency.getProperties().get(i).getLocation() == "Sour") {
        System.out.println(myAgency.getProperties().get(i));
        System.out.println();
      }
    }
    System.out.println(myAgency.countAppartments());
    System.out.println(myAgency.searchForApartment(5));
    myAgency.updatePriceLand(500);

    ArrayList<Apartment> duplexs = myAgency.findDuplexApartments(1000000);
    System.out.println(duplexs.size());
    scanner.close();
  }

}
