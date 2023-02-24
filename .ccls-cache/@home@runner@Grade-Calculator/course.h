#include "assignment.h"
#include "weight.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class course {
public:
  // constructor
  course();
  course(string name, string desc);

  // setter
  void SetName(string name);
  void SetDescr(string desc);

  // getter
  string GetName();
  string GetDesc();
  double GetFinal();

  // other
  void addWork(assignment work);
  void removeWork(assignment work);
  void addWeight(weight calc);
  void removeWeight(weight calc);
  double calcAssignAvg(string cat);
  double calcAverage();
  
  void AddFinal(double sum);
  void printWork(weight temp);
  void printCourse();

  vector<assignment> GetWorkList();
  vector<weight> GetWeightList();
private:
  string courseName;
  string courseDescription;
  vector<assignment> courseWork;
  vector<weight> weightList;
  double finalGrade;
};