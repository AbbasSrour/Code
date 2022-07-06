package Q1;

import Q1.Room;

public class Hall extends Room {
  private double size = 100;
  private String wallColor;

  public Hall(int number, double size, String wallColor) {
    super(number);
    if (size > 0)
      this.size = size;
    this.wallColor = wallColor.toLowerCase();
  }

  public void setSize(double size) {
    if (size > 0)
      this.size = size;
  }

  public void setWallColor(String wallColor) {
    this.wallColor = wallColor.toLowerCase();
  }

  public double getSize() {
    return size;
  }

  public String getWallColor() {
    return wallColor;
  }

  @Override
  public String toString() {
    return super.toString();
  }
}
