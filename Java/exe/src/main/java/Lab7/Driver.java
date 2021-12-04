package Lab7;

import java.util.Scanner;

public class Driver {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    CreditCardPayment Pay[] = new CreditCardPayment[4];
    for (int i = 0; i < Pay.length; i++) {
      System.out.print("please enter the amount to pay :");
      int amount = scanner.nextInt();
      System.out.print("please enter the Currency :");
      String currency = scanner.next();
      System.out.print("please enter the credit card number : ");
      int number = scanner.nextInt();
      Pay[i] = new CreditCardPayment(currency, amount, number);
    }
    for (int i = 0; i < Pay.length; i++) {
      for (int j = i + 1; j < Pay.length; j++) {
        if (Pay[i].getAmount() > Pay[j].getAmount()) {
          CreditCardPayment temp;
          temp = Pay[i];
          Pay[i] = Pay[j];
          Pay[j] = temp;
        }
      }
    }
    for (int i = 0; i < Pay.length; i++) {
      System.out.println(Pay[i].toString());
    }
  }
}
