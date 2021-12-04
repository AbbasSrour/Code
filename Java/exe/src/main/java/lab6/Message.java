package lab6;

import java.util.ArrayList;

public class Message {
  UserAccount Sender;
  ArrayList<UserAccount> Recievers;
  String Body;

  Message(UserAccount sender, ArrayList<UserAccount> recievers, String message) {
    this.Sender = sender;
    this.Recievers = recievers;
    this.Body = message;
  }

  public String getBody() {
    return this.Body;
  }

  public ArrayList<UserAccount> getRecievers() {
    return this.Recievers;
  }

}
