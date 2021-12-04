package Lab7;
public class CreditCardPayment extends Payment{
  private int cardNumber;

  CreditCardPayment(String currency, double amount, int cardNumber){
    super(amount, currency);
    this.cardNumber = cardNumber;
  }
  
  public boolean Authorize(){
    if(this.Convert() <= 1000000)
      return true;
    return false;
  }
  
  public String toString(){
    if (Authorize()==true){
      String str= "Card Number: " + this.cardNumber + "\n"+"Amount: " + this.getAmount() + "\n" + "Currency: " + this.getCurrency() + "\n"+ "Equivelant LBP: "+ this.Convert() + "\n";
      return str;
    }
    else return "Operation Failed";
  }
}
