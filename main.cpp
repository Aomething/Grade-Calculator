/*
  The goal here is to take in .txt equivalents of a course syllabus pdf,
  take in the name of the course, grading/weighting amounts (%), and then
  take in another .txt file full of grades on assignments to calculate a
  grade average. Also, output all info to a new file, named with the
  pattern:

      Semester_Year_weighted_grades.txt

  where the semester is either Spring (Sp) or Fall (Fa)
  and Year is the last 2 digits of the current year, 2023 = '23'

  Inputs:
  syllabus.txt
  grades.txt

  Outputs:
  calculations -> cout
  calculations -> XX_YY_weighted_grades.txt


MAIN COURSE MENU
a - Add course to current course list
d - Search by name for a course, delete if found, return error if not found
m - Search by name for a course, prompt to modify if found, return error if not found
s - Search by name for a course, prompt for an assignment to add if found, return error if not found
t - Search by name for a course, 
  if course found: prompt for assignment name to search for
    if assignment found:
      delete assignment matching name
    if assignment not found:
      return item not found
  if course not found:
    return item not found
p - Print all courses for viewing
i - Import file by name
o - export to file by name
q - Quit

*/
#include "course.h"
#include <fstream>

void printMenu(vector<course> list) {
  char cmd;
  bool valid = true;
  assignment tempAsn;
  weight tempWgt;
  course tempCrs;
  string tempStr;
  double tempWght;
  int tempInt;
  int courseNum = list.size();
  ifstream iFile;
  ofstream oFile;
  
  while (cmd != 'q') {
    while (valid) {
      cout << "MENU\n" 
      << "a - Add a course to the current list\n"
      << "d - Delete a course from the current list\n"
      << "m - Modify course\n"
      << "s - Add an assignment to a course\n"
      << "t - Delete an assignment from a course\n" 
      << "p - Print all courses for viewing\n"
      << "i - Import course info\n"
      << "o - Export course info\n"
      << "q - Quit\n"
      << "\nChoose an option:\n\n";
      
      cin >> cmd;
      switch(cmd) {
        case 'a':
          valid = true;
          cout << "Enter the name for the course: \n" << endl;
          cin >> tempStr;
          tempCrs.SetName(tempStr);
          cout << "Enter the description for the course: \n" << endl;
          cin >> tempStr;
          tempCrs.SetDescr(tempStr);
          list.push_back(tempCrs);
        break;
        case 'd':
          valid = true;
        break;
        case 'm':
          valid = true;
        break;
        case 's':
          valid = true;
          cout << "Enter the name of the course to add to: " << endl;
          cin >> tempStr;
          tempInt = list.size();
          for (int i = 0; i < tempInt; i++) {
            if (list[i].GetName() == tempStr) {
               cout << "Enter a category for weighting:\n" << endl;
              
            }
          }
        break;
        case 't':
          valid = true;
          cout << "Enter the name of the course to take away from: " << endl;
          cin >> tempStr;
          tempInt = list.size();
          for (int i = 0; i < tempInt; i++) {
            if (list[i].GetName() == tempStr) {
               
            }
          }
        break;
        case 'p':
          valid = true;
          tempInt = list.size();
          for (int i = 0; i < tempInt; i++) {
            list[i].printCourse(cout);
            cout << "\n";
          }
        break;
        case 'i':
          valid = true;
        break;
        case 'o':
          valid = true;
          cout << "Outputting all info to \'output.txt\'" << endl;
          oFile.open("output.txt");
          oFile << courseNum << endl; //write to file the number of courses
          for (int i = 0; i < courseNum; i++) {
            oFile << list[i].GetName() << endl;
            oFile << list[i].GetDesc() << endl;
            tempInt = list[i].GetWeightList().size(); 
            oFile << tempInt << endl; //write to file number of weighting categories
            for (int j = 0; j < tempInt; j++) {
              oFile << list[i].GetWeightList().at(j).GetName() << endl;
              oFile << list[i].GetWeightList().at(j).GetWeight() << endl;
            }
            tempInt = list[i].GetWorkList().size(); 
            cout << tempInt; //write to file the number of assignments in current course 
            for (int k = 0; k < tempInt; k++) {
              oFile << list[i].GetWorkList().at(k).GetCat() << endl;
              oFile << list[i].GetWorkList().at(k).GetName() << endl;
              oFile << list[i].GetWorkList().at(k).GetDesc() << endl;
              oFile << list[i].GetWorkList().at(k).GetGrade() << endl;
            }
          }
          oFile.close();
        break;
        case 'q':
          valid = true;
          cout << "Stopping program\n";
          return;
        break;
        default:
          cout << "Invalid input\n";
        break;
      }
    }
  }

  
  return;
}

int main() {
  string tempName;
  string tempDesc;
  double tempGrade;
  assignment tempAssign;
  course tempCourse;  
  vector<course> courseList;
  
  assignment a1("hw 1", "homework #1", "homework", 85);
  assignment a2("hw 2", "homework #2", "homework", 95);
  assignment a3("qz 1","quiz #1","quizzes", 75);
  assignment a4("qz 2", "quiz #2", "quizzes", 85);
  assignment a5("ex 1", "exam 1", "exams", 50);
  assignment a6("ex 2","exam 2","exams", 85);
  
  weight w1("homework",0.4);
  weight w2("quizzes",0.2);
  weight w3("exams", 0.6);

  tempCourse.addWork(a1);
  tempCourse.addWork(a2);
  tempCourse.addWork(a3);
  tempCourse.addWork(a4);
  tempCourse.addWork(a5);
  tempCourse.addWork(a6);

  tempCourse.addWeight(w1);
  tempCourse.addWeight(w2);
  tempCourse.addWeight(w3);

  //tempCourse.printCourse();
  cout << "\n\n\n";
  
  //tempCourse.calcAverage();
  //cout << "Final Weighted Grade: " << tempCourse.GetFinal();
  courseList.push_back(tempCourse);
  
  printMenu(courseList);
  
  return 0;
}

