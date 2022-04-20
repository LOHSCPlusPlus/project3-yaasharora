#pragma once
#include <fstream>
using namespace std;

//class and functions 
class Cereal{
public:
  Cereal();
  void printCereal(ostream &out);
  void readCereal(ifstream &inFile);
  void addCereal();
  double getnumCalories();
private:
  enum {MAX_NAME_LEN=100};
  char name[MAX_NAME_LEN];
  double numCalories;
  double gramsofProtein;
  double gramsofFat;
  double gramsofSodium;
  double gramsofFiber;
  double gramsofCarbs;
  double gramsofSugar;
  double cupsPerServing;
}; 