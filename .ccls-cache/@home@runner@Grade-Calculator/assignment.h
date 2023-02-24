#include <iostream>
#include <string>

using namespace std;

class assignment {
public:
  // constructor
  assignment();
  assignment(string name, string desc, string cat, double grd);

  // setter
  void SetName(string name);
  void SetDesc(string desc);
  void SetCat(string cat);
  void SetGrade(double grd);
  void AddGrade(double grd);

  // getter
  string GetName();
  string GetDesc();
  string GetCat();
  double GetGrade();

private:
  string Name;
  string Description;
  string Category;
  double Grade;
};