package Lab7;

import java.util.Scanner;

public class Payment {
  private double Amount;
  private String Currency;
  Scanner scanner = new Scanner(System.in);

  Payment(double Amount, String Currency) {
    this.Amount = Amount;
    if (Currency.equals("USD") || Currency.equals("EURO") || Currency.equals("LBP"))
      this.Currency = Currency;

    else {
      while (!Currency.equals("USD") && !Currency.equals("EURO") && !Currency.equals("LBP")) {
        System.out.print("Please enter one of the accepted currencies:");
        Currency = scanner.next();
        this.Currency = Currency;
      }
    }
  }

  public double Convert() {
    double lbp;
    if (Currency.equals("USD"))
      lbp = this.Amount * 1500;
    else if (Currency.equals("EURO"))
      lbp = this.Amount * 1.5 * 1500;
    else
      lbp = this.Amount;

    return lbp;
  }

  public String toString() {
    String str = "Amount: " + this.Amount + "\n" + "Currency: " + this.Currency + "\n" + "Equivelant in LBP: "
        + this.Convert();
    return str;
  }

  public double getAmount() {
    return this.Amount;
  }

  public String getCurrency() {
    return this.Currency;
  }
}
