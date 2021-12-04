package Lab5;

public class Account {
  String id;
  String name;
  int balance;

  public Account(String id, String Name) {
    this.id = id;
    this.name = Name;
    this.balance = 0;
  }

  public Account(String id, String name, int balance) {
    this.id = id;
    this.name = name;
    this.balance = balance;
  }

  public String getID() {
    return this.id;
  }

  public String getName() {
    return this.name;
  }

  public int getBalance() {
    return this.balance;
  }

  public int Credit(int credit) {
    this.balance += credit;
    return this.balance;
  }

  public int Debit(int debit) {

    if (debit <= this.balance)
      this.balance -= debit;
    else
      System.out.println("The amount exceeds the current balance");
    return this.balance;
  }

  public int Transfer(Account X, int sum) {
    if (sum <= this.balance) {
      X.balance += sum;
      this.balance -= sum;
    } else
      System.out.println("The exceeds your current balance");

    return this.balance;
  }

  public String toString() {
    String str = "Acount[" + this.id + ",name=" + this.name + ",balance=" + this.balance + "]";
    return str;
  }
}
