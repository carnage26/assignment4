#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string_view>
using namespace std;
class student {
private:
  string name, roll_no, marks1, marks2, marks3, marks4, marks5, marks6;

public:
  void menu();
  void insert();
  void display();
  void modify();
};
void student::menu() {
menustart:
  int choice;
  char x;
  (void) system("cls");
  cout << "\t\t\t-----------------------------" << endl;
  cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
  cout << "\t\t\t-----------------------------" << endl;
  cout << "\t\t\t 1. Enter New Record" << endl;
  cout << "\t\t\t 2. Display Record" << endl;
  cout << "\t\t\t 3. Modify Record" << endl;
  cout << "\t\t\t 0. Exit" << endl;
  cout << "\t\t\t---------------------------" << endl;
  cout << "\t\t\tChoose Option:[1/2/3/4]" << endl;
  cout << "\t\t\t---------------------------" << endl;
  cout << "Enter Your Choose: ";
  cin >> choice;
  switch (choice) {
  case 1:
    do {
      insert();
      cout << "\n\t\t\t Add Another Student Record (Y,N): ";
      cin >> x;
    } while (x == 'y' || x == 'Y');
    break;
  case 2:
    display();
    break;
  case 3:
    modify();
    break;

  case 0:
    exit(0);
  default:
    cout << "\n\t\t\t Invalid choice... Please Try Again..";
  }
  goto menustart;
}
void student::insert() // add student details
{
  (void) system("cls");
  fstream file;
  cout << "\n------------------------------------------------------------------"
          "-----------------------------------";
  cout << "\n------------------------------------- Add Student Details "
          "---------------------------------------------"
       << endl;
  cout << "\t\t\tEnter Name: ";
  cin >> name;
  cout << "\t\t\tEnter Roll No.: ";
  cin >> roll_no;
  cout << "\t\t\t Enter marks1: ";
  cin >> marks1;
  cout << "\t\t\tEnter marks2: ";
  cin >> marks2;
  cout << "\t\t\tEnter marks3: ";
  cin >> marks3;
  cout << "\t\t\t Enter marks 4: ";
  cin >> marks4;
  cout << "\t\t\t Enter marks5: ";
  cin >> marks5;
  file.open("studentRecord.txt", ios::app | ios::out);
  file << " " << name << " " << roll_no << " " << marks1 << " " << marks2 << " "
       << marks3 << " " << marks4 << " " << marks5 << "\n";
  file.close();
}
void student::display() {
  (void) system("cls");
  fstream file;
  int total = 1;
  cout << "\n------------------------------------------------------------------"
          "-------------------------------------"
       << endl;
  cout << "------------------------------------- Student Record Table "
          "--------------------------------------------"
       << endl;
  file.open("studentRecord.txt", ios::in);
  if (!file) {

    cout << "\n\t\t\tNo Data Is Present...";
    file.close();
  } else {
    file >> name >> roll_no >> marks1 >> marks2 >> marks3 >> marks4 >> marks5;
    while (!file.eof()) {
      cout << "\n\n\t\t\t Student No.: " << total++ << endl;
      cout << "\t\t\t Student Name: " << name << endl;
      cout << "\t\t\t Student Roll No.: " << roll_no << endl;
      cout << "\t\t\t Student Marks1: " << marks1 << endl;
      cout << "\t\t\t Student Marks2: " << marks2 << endl;
      cout << "\t\t\t Student Marks3: " << marks3 << endl;
      cout << "\t\t\t Student Marks4 " << marks4 << endl;
      cout << "\t\t\t Student Marks5 " << marks5 << endl;
      file >> name >> roll_no >> marks1 >> marks2 >> marks3 >> marks4 >> marks5;
    }
    if (total == 0) {
      cout << "\n\t\t\tNo Data Is Present...";
    }
  }
  file.close();
}
void student::modify() // Modify Students Details
{
  (void) system("cls");
  fstream file, file1;
  string rollno;
  int found = 0;
  cout << "\n------------------------------------------------------------------"
          "-------------------------------------"
       << endl;
  cout << "------------------------------------- Student Modify Details "
          "------------------------------------------"
       << endl;
  file.open("studentRecord.txt", ios::in);
  if (!file) {
    cout << "\n\t\t\tNo Data is Present..";
  } else {
    cout << "\nEnter Roll No. of Student which you want to Modify: ";
    cin >> rollno;
    file1.open("record.txt", ios::app | ios::out);
    file >> name >> roll_no >> marks1 >> marks2 >> marks3 >> marks4 >> marks5;
    while (!file.eof()) {
      if (rollno != roll_no)
        file1 << " " << name << " " << roll_no << " " << marks1 << " " << marks2
              << " " << marks3 << " " << marks4 << " " << marks5 << "\n";
      else {
        cout << "\n\t\t\tEnter Name: ";
        cin >> name;
        cout << "\t\t\tEnter Roll No.: ";
        cin >> roll_no;
        cout << "\t\t\tEnter Marks1: ";
        cin >> marks1;
        cout << "\t\t\tEnter Marks2: ";
        cin >> marks2;
        cout << "\t\t\tEnter Marks3: ";
        cin >> marks3;
        cout << "\t\t\tEnter Marks4: ";
        cin >> marks4;
        cout << "\t\t\tEnter Marks5: ";
        cin >> marks5;
        file1 << " " << name << " " << roll_no << " " << marks1 << " " << marks2
              << " " << marks3 << " " << marks4 << " " << marks5 << "\n";
        found++;
      }
      file >> name >> roll_no >> marks1 >> marks2 >> marks3 >> marks4 >> marks5;
      if (found == 0) {
        cout << "\n\n\t\t\t Student Roll No. Not Found....";
      }
    }
    file1.close();
    file.close();
    remove("studentRecord.txt");
    rename("record.txt", "studentRecord.txt");
  }
}
int main() {
  student project;
  project.menu();
  return 0;
}