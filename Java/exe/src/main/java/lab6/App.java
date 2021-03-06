package lab6;

import java.lang.Character;
import java.util.ArrayList;
import java.util.Scanner;

public class App {
  static Scanner scanner = new Scanner(System.in);

  public static UserAccount createAccount() {
    String fn, ln, password;
    System.out.print("Please enter your first name: ");
    fn = scanner.next();
    System.out.print("Please enter your last name: ");
    ln = scanner.next();
    System.out.print("Please enter your password: ");
    password = scanner.next();

    if (password.length() < 8) {
      while (password.length() < 8) {
        System.out.print("Please enter a password >= than 8 : ");
        password = scanner.next();
      }
    }
    int check = passCheck(password);
    while (check == 0) {
      System.out.print("Please enter a password with atleast one uppercase letter : ");
      password = scanner.next();
      check = passCheck(password);
    }
    UserAccount newAccount = new UserAccount(fn, ln, password);
    return newAccount;
  }

  public static int passCheck(String password) {
    int check = 0;
    for (int i = 0; i < password.length() && check == 0; i++) {
      char a = password.charAt(i);
      if (Character.isUpperCase(a) == true)
        check++;
    }
    return check;
  }

  public static void Freinds(UserAccount UA) {
    ArrayList<UserAccount> freinds = new ArrayList<UserAccount>();
    for (int i = 0; i < UA.getMailBox().size(); i++) {
      int red = 0;
      for (int j = 0; j < freinds.size() && red == 0; j++) {
        if (UA.getMailBox().get(i).Sender == freinds.get(j))
          red++;
      }
      if (red == 0)
        freinds.add(UA.getMailBox().get(i).Sender);
    }
    for (int i = 0; i < freinds.size(); i++) {
      String freind = freinds.get(i).printInfo();
      System.out.println("Your freind " + i + " : " + freind);
    }
  }

  public static void main(String[] args) {
    // TODO Auto-generated method stub
    UserAccount u1, u2, u3;
    u1 = createAccount();
    u2 = createAccount();
    u3 = createAccount();

    System.out.println(u1.getEmail());
    System.out.println(u2.getEmail());
    System.out.println(u3.getEmail());

    ArrayList<UserAccount> r = new ArrayList<UserAccount>();
    r.add(u2);
    r.add(u3);
    u1.sendMessage("hello", r);
    System.out.println(u2.getMailBox().get(0).getBody());
    Freinds(u2);

  }
}
