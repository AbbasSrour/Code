package lab6;

import java.util.ArrayList;

public class UserAccount {
  private String firstName;
  private String lastName;
  private String emailAddress;
  private String password;
  private ArrayList<Message> Mailbox;
  private static ArrayList<String> UsersEmails = new ArrayList<String>();
  private static ArrayList<UserAccount> Users = new ArrayList<UserAccount>();

  UserAccount(String name1, String name2, String password) {
    this.firstName = name1;
    this.lastName = name2;
    this.password = password;
    Mailbox = new ArrayList<Message>();
    int c = 0;
    this.emailAddress = this.firstName + "." + this.lastName + "@mailbox.com";
    for (int i = 0; i < Users.size(); i++) {
      if (this.emailAddress == UsersEmails.get(i)) {
        c++;
        this.emailAddress = this.firstName + "." + this.lastName + c + "@mailbox.com";
      }
    }
    UsersEmails.add(this.emailAddress);
    Users.add(this);
  }

  public Message sendMessage(String text, ArrayList<UserAccount> recipients) {
    String subject = "";
    Message myMessage = new Message(this, recipients, text);

    for (int i = 0; i < recipients.size(); i++) {
      ((recipients.get(i)).Mailbox).add(myMessage);
    }
    return myMessage;
  }

  public String readMessage(int i) {
    return this.Mailbox.get(i).getBody();
  }

  public String printInfo() {
    String S = this.firstName + " " + this.lastName;
    return S;
  }

  public ArrayList<Message> getMailBox() {
    return this.Mailbox;
  }

  public String getEmail() {
    return this.emailAddress;
  }
}
