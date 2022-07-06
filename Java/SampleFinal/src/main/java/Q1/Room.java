package Q1;

public class Room {
  int number;
  Boolean reserved = false;

  public Room(int number) {
    this.number = number;
  }

  public void setRoomNumber(int number) {
    if (number > 0)
      this.number = number;
  }

  public void setReserved(Boolean reserved) {
    this.reserved = reserved;
  }

  public int getRoomNumber() {
    return number;
  }

  public Boolean getReserved() {
    return reserved;
  }

  public String toString() {
    String S;
    S = "";
    return S;

  }
}
