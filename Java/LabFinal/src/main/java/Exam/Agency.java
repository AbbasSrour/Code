package Exam;

import Exam.Property;
import java.util.ArrayList;

public class Agency {
  private String name;
  private ArrayList<Property> properties;

  public Agency(String name) {
    this.name = name;
    this.properties = new ArrayList();
  }

  public void addProperty(Property P) {
    this.properties.add(P);
  }

  public ArrayList<Property> getProperties() {
    return properties;
  }

  public String getName() {
    return name;
  }

  public void displayLands() {
    for (int i = 0; i < this.properties.size(); i++) {
      if (this.properties.get(i) instanceof Land)
        System.out.println(this.properties.get(i));
    }
  }

  public int countAppartments() {
    int count = 0;
    for (int i = 0; i < this.properties.size(); i++) {
      if (this.properties.get(i) instanceof Apartment)
        count++;
    }
    return count;
  }

  public Apartment searchForApartment(int nbOfRooms) {
    Apartment appartment;
    for (int i = 0; i < this.properties.size(); i++) {
      if (this.properties.get(i) instanceof Apartment) {
        appartment = (Apartment) this.properties.get(i);
        if (appartment.getNbOfRooms() == nbOfRooms) {
          return appartment;
        }
      }
    }
    return null;
  }

  public void updatePriceLand(int increase) {
    for (int i = 0; i < this.properties.size(); i++) {
      if (this.properties.get(i) instanceof Land)
        this.properties.get(i).setPrice(this.properties.get(i).getPrice() + increase);
    }
  }

  public ArrayList<Apartment> findDuplexApartments(int price) {
    ArrayList<Apartment> Duplexes = new ArrayList();
    Apartment myApartment;
    for (int i = 0; i < this.properties.size(); i++) {
      if (this.properties.get(i) instanceof Apartment) {
        myApartment = (Apartment) this.properties.get(i);
        if (myApartment.getDuplex()
            && myApartment.getPrice() < price) {
          Duplexes.add(myApartment);
        }
      }
    }
    return Duplexes;
  }
}
