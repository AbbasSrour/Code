package Exam;

public class Apartment extends Property {
  private int nbOfRooms;
  private Boolean duplex;

  public Apartment(int price, String location, Double area, int nbOfRooms, Boolean duplex) {
    super(location, price, area);
    this.nbOfRooms = nbOfRooms;
    this.duplex = duplex;
  }

  public int getNbOfRooms() {
    return nbOfRooms;
  }

  public Boolean getDuplex() {
    return duplex;
  }

  public void setNbOfRooms(int nbOfRooms) {
    this.nbOfRooms = nbOfRooms;
  }

  public void setDuplex(Boolean duplex) {
    this.duplex = duplex;
  }

  @Override
  public String toString() {
    String S;
    if (this.getDuplex())
      S = "The Appartment has " + this.nbOfRooms + " rooms, and is a duplex. " + super.toString();
    else
      S = "The Appartment has " + this.nbOfRooms + " rooms, and is not a duplex. " + super.toString();
    return S;
  }

}
