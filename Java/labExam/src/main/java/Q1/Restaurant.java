package Q1;

public class Restaurant {
  private String name;
  private String address;
  private int stars;
  private String speciality;
  private double averageDishPrice;

  public Restaurant(String n, String a, int s, String sp, double ave) {
    this.name = n;
    this.address = a;
    this.stars = s;
    this.speciality = sp;
    this.averageDishPrice = ave;
  }

  public void setStars(int stars) {
    this.stars = stars;
  }

  public String getSpeciality() {
    return this.speciality;
  }

  public Boolean isCheap() {
    if (this.averageDishPrice < 20) return true;
    return false;
  }

  @Override
  public String toString() {
    String cheapOrExpensive;
    if (this.isCheap()) cheapOrExpensive = "Cheap";
    else cheapOrExpensive = "Expensive";
    String S =
        this.name
            + " is a "
            + stars
            + " star resturant located in "
            + address
            + ". Speciality: "
            + this.speciality
            + ". "
            + this.name
            + " is "
            + cheapOrExpensive;
    return S;
  }
}
