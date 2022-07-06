package Exam;

import java.util.Scanner;

public class App {
  public static void main(String[] args) {
    University universityArray[] = new University[3];
    Scanner scanner = new Scanner(System.in);

    for (int j = 0; j < 3; j++) {
      System.out.print("Enter university name: ");
      String uName = scanner.nextLine();

      System.out.print("Enter university address: ");
      String uAddress = scanner.nextLine();

      System.out.print("Enter the number of students: ");
      int stdCount = scanner.nextInt();

      System.out.print("Enter the number of instructors: ");
      int instCount = scanner.nextInt();

      String students[] = new String[stdCount];
      String stdName;
      for (int i = 0; i < stdCount; i++) {
        System.out.print("Enter Student Name: ");
        stdName = scanner.nextLine();
        scanner.next();
        students[i] = stdName;
      }

      String instructors[] = new String[instCount];
      String instName;
      for (int i = 0; i < stdCount; i++) {
        System.out.print("Enter Instructor Name: ");
        instName = scanner.nextLine();
        scanner.next();
        students[i] = instName;
      }
      universityArray[j] = new University(uName, uAddress, stdCount, instCount);
    }
    System.out.println("The number of all students is: " + universityArray[0].getAllStdCount());
    System.out.print("The number of all students is: " + universityArray[0].getAllInstCount());

    for (int i = 0; i < universityArray[i].getStdCount(); i++) {
      String Address[] = universityArray[i].getAddress().split(",");
      if (Address[2].equals("Lebanon") || Address[2].equals("Palestaine")) {
        System.out.print(universityArray[i]);
      }
    }

    for (int i = 0; i < universityArray.length; i++) {
      String studentArray[] = universityArray[i].getStudents();
      int count = 0;
      for (int j = 0; j > universityArray[i].getStdCount(); j++) {
        if (studentArray[0].charAt(0).equals("A")) {
          count++;
        }
      }
      if (count == universityArray[i].getStdCount())
        System.out.print(universityArray[i]);
    }

  }
}
