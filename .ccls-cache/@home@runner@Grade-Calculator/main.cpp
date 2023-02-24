/*

The goal here is to take in data from the user or from an input .txt file, and keep track of a series of courses, all the assignments for each one, and the weight that each assignment has. The user will be able to add and remove courses, add and remove assignments from individual courses, and output all info to either the screen or an output file. The format of the output file should be structured so the same program can read and import the data back into memory at a later date. 

Further functionality might include having it sift through a .txt equivalent of a syllabus and automatically finding the weights for the course and automatically create a course and assign those weights to it. 

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
p - Print all courses for viewing, as well as the current average for the each class
i - Import file by name
o - export to file by name
q - Quit

*/
#include "course.h"
#include <fstream>

void printMenu(vector<course> &list) {
  char cmd;
  bool valid = true;
  assignment tempAsn;
  weight tempWgt;
  course tempCrs;
  string tempStr;
  double tempDoub;
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
          cin.ignore(1);
          getline(cin, tempStr);
          tempCrs.SetName(tempStr);
          cout << "Enter the description for the course: \n" << endl;
          getline(cin, tempStr);
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
          cin.ignore(1);
          cout << "Enter the name of the course to add to: " << endl;
          getline(cin, tempStr);
          tempInt = list.size();
          for (int i = 0; i < tempInt; i++) {
            if (list[i].GetName() == tempStr) {  //found selected course
              cout << "Enter a category to add to weights:\n(type 'none' to add an assignment to an existing category)\n" << endl;
              getline(cin, tempStr);
              if (tempStr == "none") {
                cout << "Enter a category to add an assignment to:\n";
                getline(cin, tempStr);
                tempInt = list[i].GetWeightList().size();
                for (int j = 0; j < tempInt; j++) { 
                  if (list[i].GetWeightList().at(j).GetName() == tempStr) {
                    //found selected category
                    tempAsn.SetCat(tempStr);
                    cout << "Enter a name for the new assignment:\n";
                    getline(cin, tempStr);
                    tempAsn.SetName(tempStr);
                    cout << "Enter the description for the new assignment:\n";
                    getline(cin, tempStr);
                    tempAsn.SetDesc(tempStr);
                    cout << "Enter the grade recieved for the assignment:\n";
                    cin >> tempDoub;
                    cout << tempDoub << endl;
                    tempAsn.SetGrade(tempDoub);
                    list[i].GetWorkList().push_back(tempAsn);
                  }
                }
              }
              else {
                //create new category, then add an assignment to it
                tempWgt.SetName(tempStr);
                cout << "Enter the weight of the category (decimal form)" << endl;
                cin >> tempDoub;
                tempWgt.SetWeight(tempDoub);
                list[i].GetWeightList().push_back(tempWgt);
                //cin.ignore(1);
                tempAsn.SetCat(tempStr);
                cout << "Enter a name for the new assignment:\n";
                getline(cin, tempStr);
                tempAsn.SetName(tempStr);
                cout << "Enter the description for the new assignment:\n";
                getline(cin, tempStr);
                tempAsn.SetDesc(tempStr);
                cout << "Enter the grade recieved for the assignment:\n";
                cin >> tempDoub;
                tempAsn.SetGrade(tempDoub);
                list[i].GetWorkList().push_back(tempAsn);
              }
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
            list[i].calcAverage();
            cout << "Final Weighted Grade: " << list[i].GetFinal() << "\n\n";
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
            oFile << tempInt << endl; //write to file the number of assignments in current course 
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
  
  cout << "\n\n\n";
  
  tempCourse.calcAverage();
  //cout << "Final Weighted Grade: " << tempCourse.GetFinal() << endl;
  courseList.push_back(tempCourse);
  
  printMenu(courseList);
  
  return 0;
}

