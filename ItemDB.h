#pragma once
#include "ItemClass.h"
using namespace std;

class cerealDB {
public:
  void printList();
  void printUpdatedList(const char fileName[]);
  int readCerealData();
  void addCereal();
  void removeCereal();
  void printbyCals();
  void Menu();
  cerealDB();
private:
  enum {MAX_NUM_CEREALS = 100};
  Cereal cerealList[MAX_NUM_CEREALS];
  int numCereal;
}; 