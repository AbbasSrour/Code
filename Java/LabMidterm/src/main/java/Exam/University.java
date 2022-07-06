package Exam;

import java.sql.Array;

public class University {
  private String uName = "undefined";
  private String uAddress = "dd,dd,dd";
  private String students[];
  private String instructors[];
  private int stdCount = 0;
  private int instCount = 0;
  private static int allStdCount = 0;
  private static int allInstCount = 0;

  public University(String uniName, String uniAddress, int stdCount, int instCount) {
    this.uName = uniName;
    this.uAddress = uniAddress;
    this.stdCount = stdCount;
    this.instCount = instCount;
    this.students = new String[this.stdCount];
    this.instructors = new String[this.instCount];
  }

  public String getAddress() {
    return uAddress;
  }

  // public String getuName() {
  // return uName;
  // }

  public String[] getStudents() {
    return students;
  }

  public String[] getInstructors() {
    return instructors;
  }

  public int getStdCount() {
    return stdCount;
  }

  public int getInstCount() {
    return instCount;
  }

  public void addStudent(String name) {
    for (int i = 0; i < this.stdCount; i++) {
      if (this.students[i] == null) {
        this.students[i] = name;
        this.allStdCount++;
        return;
      }
    }
  }

  public void addInstructor(String name) {
    for (int i = 0; i < this.instCount; i++) {
      if (this.instructors[i] == null) {
        this.instructors[i] = name;
      }
      this.allInstCount++;
      return;
    }
  }

  public static int getAllStdCount() {
    return allStdCount;
  }

  public static int getAllInstCount() {
    return allInstCount;
  }

  @Override
  public String toString() {
    String S = "University: \n" + "Name= " + this.uName + " Address= " + this.getAddress() + "\n"
        + "Srudents at the university are:\n";
    for (int i = 0; i < this.getStdCount(); i++) {
      S = S + this.students[i] + "\n";
    }
    S = S + " Instructors at the university are:\n";
    for (int i = 0; i < this.getInstCount(); i++) {
      S = S + this.instructors[i] + "\n";
    }
    return S;
  }
}
