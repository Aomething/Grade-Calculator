#include "weight.h"

weight::weight() {
  categoryName = "unnamed weight";
  perc = 0.0;
}

weight::weight(string name, double num) {
  categoryName = name;
  perc = num;
}

// setter 
void weight::SetName(string name) {
  categoryName = name;
}

void weight::SetWeight(double setTotal) {
  perc = setTotal;
}

// getter
string weight::GetName() {
  return categoryName;
}

double weight::GetWeight() {
  return perc;
}