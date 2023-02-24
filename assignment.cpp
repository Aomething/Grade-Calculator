#include "assignment.h"

//constructor
assignment::assignment() {
  Name = "unnamed assignment";
  Description = "purely indescribable";
  Category = "uncategorized";
  Grade = -1.0;
}

assignment::assignment(string name, string desc, string cat, double grd) {
  Name = name;
  Description = desc;
  Category = cat;
  Grade = grd;
}

//setter
void assignment::SetName(string name) {
  Name = name;
  return;
}
void assignment::SetCat(string cat) {
  Category = cat;
  return;
}

void assignment::SetDesc(string desc) {
  Description = desc;
  return;
}

void assignment::SetGrade(double grd) {
  Grade = grd;
  return;
}

void assignment::AddGrade(double grd) {
  Grade += grd;
  return;
}

//getter
string assignment::GetName() {
  return Name;
}

string assignment::GetDesc() {
  return Description;
}

string assignment::GetCat() {
  return Category;
}

double assignment::GetGrade() {
  return Grade;
}