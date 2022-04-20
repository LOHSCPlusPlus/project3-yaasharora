#include <iostream>
#include "ReadUtils.h"
#include "ItemClass.h"
using namespace std;

//default constructor 
Cereal::Cereal(){
  for(int index = 0; index < MAX_NAME_LEN; index++){
    name[index] = 0;
  }
  numCalories = 0;
  gramsofProtein = 0;
  gramsofFat = 0;
  gramsofSodium = 0;
  gramsofFiber = 0;
  gramsofCarbs = 0;
  gramsofSugar = 0;
  cupsPerServing = 0;
}

//get the number of calories
double Cereal::getnumCalories(){
  return numCalories;
}

//print cereals
void Cereal::printCereal(ostream &out){
    out << name << ";";
    out << numCalories << ";";
    out << gramsofProtein << ";";
    out << gramsofFat << ";";
    out << gramsofSodium << ";";
    out << gramsofFiber << ";";
    out << gramsofCarbs << ";";
    out << gramsofSugar << ";";
    out << cupsPerServing << endl;
}

//read the list
void Cereal::readCereal(ifstream &inFile){
    inFile.get(name, Cereal::MAX_NAME_LEN, ';');
    inFile.ignore(100,';');
    inFile >> numCalories;
    inFile.ignore(100,';');
    inFile >> gramsofProtein;
    inFile.ignore(100,';');
    inFile >> gramsofFat;
    inFile.ignore(100,';');
    inFile >> gramsofSodium;
    inFile.ignore(100,';');
    inFile >> gramsofFiber;
    inFile.ignore(100,';');
    inFile >> gramsofCarbs;
    inFile.ignore(100,';');
    inFile >> gramsofSugar;
    inFile.ignore(100,';');
    inFile >> cupsPerServing;
    inFile.ignore(100,'\n');

}

//add a cereal
void Cereal::addCereal(){
      cout << "Name of the cereal to be added:" << endl;
      cin.ignore(11,'\n'); cin.getline(name, Cereal::MAX_NAME_LEN);
      numCalories = readDouble("Calorie count: ");
      gramsofProtein = readDouble("Protein count: ");
      gramsofFat = readDouble("Fat count: ");
      gramsofSodium = readDouble("Sodium count: ");
      gramsofFiber = readDouble("Fiber count: ");
      gramsofCarbs = readDouble("Carbohydrate count: ");
      gramsofSugar = readDouble("Sugar count: ");
      cupsPerServing = readDouble("Cups per serving: ");
      return;
        }

