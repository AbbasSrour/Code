package Lab5;

import java.net.StandardSocketOptions;
import java.util.Scanner;
import java.lang.Math;
import java.util.ArrayList;

public class App {
  public static ArrayList<Account> Accounts = new ArrayList<Account>();
  public static Scanner scanner = new Scanner(System.in);

  public static void main(String[] args) {
    int exitcode = 0;

    while (exitcode != 1) {
      int action;
      System.out.println("1- Create Account");
      System.out.println("2- Remove Account");
      System.out.println("3- Credit Money");
      System.out.println("4- Debit Money");
      System.out.println("5- Transfer Money");
      System.out.println("6- Print The Available Accounts");
      System.out.println("7- Exit");
      System.out.print("Please choose an action : ");
      action = scanner.nextInt();

      if (action < 0 || action > 7)
        System.out.println("Please enter a valid number");
      if (action == 1)
        createAccount();
      if (action == 2)
        removeAccount();
      if (action == 3)
        addMoney();
      if (action == 4)
        debitAccount();
      if (action == 7)
        exitcode = 1;
    }
    scanner.close();
  }

  public static void debitAccount() {
    System.out.print("Please enter the id of the account to debit to : ");
    String xID = scanner.next();
    System.out.print("Please enter the account to debit: ");
    int amount = scanner.nextInt();
    int counter = 0;
    int balance;
    while (counter < Accounts.size()) {
      if (xID == (Accounts.get(counter)).getID()) {
        balance = Accounts.get(counter).getBalance();
        int x = (Accounts.get(counter)).Debit(amount);
        if (x < balance && amount != 0)
          System.out.println("The amoubt " + amount + " has been credited to " + xID + " the balance is equal to " + x);
        break;
      } else
        counter++;
    }
    if (counter >= Accounts.size()) {
      System.out.println("The operation failed: iD invalid");
    }
  }

  public static void addMoney() {
    System.out.print("Please enter the id of the account to credit to : ");
    String xID = scanner.next();
    System.out.print("Please enter the account to credit: ");
    int amount = scanner.nextInt();

    int counter = 0;
    while (counter < Accounts.size()) {
      if (xID == (Accounts.get(counter)).getID()) {
        int x = (Accounts.get(counter)).Credit(amount);
        System.out.println("The amoubt " + amount + " has been credited to " + xID + " the balance is equal to " + x);
        break;
      } else
        counter++;
    }
    if (counter >= Accounts.size()) {
      System.out.println("The operation failed: iD invalid");
    }
  }

  public static void removeAccount() {
    System.out.print("Please enter the id of the account to delete : ");
    String xID = scanner.next();
    int counter = 0;
    while (counter < Accounts.size()) {
      if (xID == (Accounts.get(counter)).getID()) {
        Accounts.remove(counter);
        System.out.println("The account of id : " + xID + " has been removed from the List");
        break;
      } else
        counter++;
    }
    if (counter >= Accounts.size()) {
      System.out.println("The operation failed: iD invalid");
    }
  }

  public static void createAccount() {
    System.out.print("Please enter the account name :");
    String name = scanner.next();
    System.out.print("Please enter the account id : ");
    String id = scanner.next();
    System.out.print("Please enter the account balance : ");
    int balance = scanner.nextInt();
    Account A = new Account(id, name, balance);
    Accounts.add(A);
  }
}
