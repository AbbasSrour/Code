package Exam;

public class Land extends Property {
  private String type;

  public Land(String location, int price, Double area, String type) {
    super(location, price, area);
    this.type = type;
  }

  public void setType(String type) {
    this.type = type;
  }

  @Override
  public String toString() {
    return super.toString() + "This property is a " + type + " land.";
  }

}
