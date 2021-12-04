package lab4;

import java.lang.Math;

public class Polynom {
  double a;
  double b;
  double c;

  Polynom(double a, double b, double c) {
    this.a = a;
    this.b = b;
    this.c = c;
  }

  public String toString() {
    String S = (a + "x^2 +" + b + "x + " + c);
    return S;
  }

  public double[] Root() {
    double roots[] = new double[2];
    double delta = ((this.b * this.b) - 4 * this.a * this.c);
    if (delta > 0) {
      roots[0] = ((-this.b - Math.sqrt(delta)) / (2 * this.a));
      roots[1] = ((-this.b + Math.sqrt(delta)) / (2 * this.a));
    } else if (delta < 0) {
      roots[0] = Double.NaN;
      roots[1] = Double.NaN;
    } else if (delta == 0) {
      roots[0] = roots[1] = ((-this.b + Math.sqrt(delta)) / (2 * this.a));
    }
    return roots;
  }

  public static Polynom Sum(Polynom A, Polynom B) {
    double a = A.a + B.b;
    double b = A.b + B.b;
    double c = A.c + B.c;
    Polynom result = new Polynom(a, b, c);
    return result;
  }
}
