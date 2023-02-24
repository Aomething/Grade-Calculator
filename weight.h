#include <string>
#include <iostream>

using namespace std;

class weight {
public:
  // constructor
  weight();
  weight(string name, double num);

  // setter
  void SetName(string name);
  void SetWeight(double perc);

  // getter
  string GetName();
  double GetWeight();

private:
  string categoryName;
  double perc;
};