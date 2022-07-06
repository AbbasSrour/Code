package Exam;

public class Property {
  private String location;
  private int price;
  private Double area;

  public Property(String location, int price, Double area) {
    this.location = location;
    this.price = price;
    this.area = area;
  }

  public int getPrice() {
    return price;
  }

  public Double getArea() {
    return area;
  }

  public String getLocation() {
    return location;
  }

  public void setPrice(int price) {
    this.price = price;
  }

  public void setArea(Double area) {
    this.area = area;
  }

  public void setLocation(String location) {
    this.location = location;
  }

  @Override
  public String toString() {
    String S = "The property is " + this.area + " big, located at " + this.location + " and is priced at " + this.price
        + ".";
    return S;
  }
}
