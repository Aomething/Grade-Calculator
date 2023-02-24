#include "course.h"



course::course() {
  courseName = "unnamed course";
  courseDescription = "absolutely indescribable";
}

course::course(string name, string desc) {
  courseName = name;
  courseDescription = desc;
}

//setter
void course::SetName(string name) {
  courseName = name;
  return;
}

void course::SetDescr(string desc) {
  courseDescription = desc;
  return;
}

//getter
string course::GetName() {
  return courseName;
}

string course::GetDesc() {
  return courseDescription;
}

void course::AddFinal(double sum) {
  finalGrade += sum;
  return;
}

double course::GetFinal() {
  return finalGrade;
}

//other
void course::addWork(assignment work) {
  courseWork.push_back(work);
  return;
}

void course::removeWork(assignment work) {
  return;
}

void course::addWeight(weight calc) {
  weightList.push_back(calc);
  return;
}
void course::removeWeight(weight calc) {
  return;
}

void course::printWork(weight temp) {
  //print all the weighted grades of a given category
  int len = courseWork.size();
  cout << "Category: " << temp.GetName() << endl;
  cout << "Weight: " << temp.GetWeight() << endl;
  for (int i = 0; i < len; i++) {
    if (temp.GetName() == courseWork[i].GetCat()) {
      cout << "  Assignment Name: " << courseWork[i].GetName() << endl;
      cout << "  Grade: " << courseWork[i].GetGrade() << endl;
    }
  }
  
  return;
}

void course::printCourse() {
  int len = weightList.size();
  cout << "Course: " << courseName << endl;
  cout << "Description: " << courseDescription << endl;
  
  
  cout << "Info: \n" << endl;
  cout << "Number of Weighted Categories: " << len << "\n" << endl;
  for (int i = 0; i < len; i++) {
    printWork(weightList[i]);
    calcAssignAvg(weightList[i].GetName());
    cout << endl;
  }
  return;
}

vector<assignment> course::GetWorkList() {
  return courseWork;
}

vector<weight> course::GetWeightList() {
  return weightList;
}
double course::calcAssignAvg(string cat) {
  //Average grade for a given category
  int assigns = courseWork.size();
  //cout << "number of assignments: " << assigns << endl;
  double total = 0.0;
  double count = 0.0;
  for (int i = 0; i < assigns; i++) {
    if (courseWork[i].GetCat() == cat) {
      cout << "";
      total += courseWork[i].GetGrade();
      count += 1.0;
    }
  }
  //cout << "Average for the category (unweighted): " << total / count << endl;
  return total / count;
}

double course::calcAverage() {
  int courseNum = courseWork.size();
  int weightNum = weightList.size();
  double tempValue;
  double average;
  //printCourse();
  for (int i = 0; i < weightNum; i++) {
    AddFinal(calcAssignAvg(weightList[i].GetName()) * weightList[i].GetWeight());
  }
  return GetFinal();
}