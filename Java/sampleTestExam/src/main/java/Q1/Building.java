package Q1;

public class Building {
  int numOfFloors;
  int numAudiotoriom;

  public Building(int numOfFloors, int numAudiotoriom) {
    this.numOfFloors = numOfFloors;
    this.numAudiotoriom = numAudiotoriom;
  }

  public int getNumOfFloors() {
    return numOfFloors;
  }

  public int getNumAudiotoriom() {
    return numAudiotoriom;
  }

  public void setNumOfFloors(int numOfFloors) {
    this.numOfFloors = numOfFloors;
  }

  public void setNumAudiotoriom(int numAudiotoriom) {
    this.numAudiotoriom = numAudiotoriom;
  }

  @Override
  public String toString() {
    String S = " " + this.numAudiotoriom + " eha " + this.numOfFloors;
    return S;
  }

}
