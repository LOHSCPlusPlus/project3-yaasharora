#include <iostream>
#include "ReadUtils.h"
#include "ItemDB.h"
using namespace std;


cerealDB::cerealDB(){
  numCereal = 0;
  readCerealData();
}

void cerealDB::printList() {
    for (int index = 0; index < numCereal; index++) {
        cout << "Index " << index << ": ";
        cerealList[index].printCereal(cout);
    }
}

void cerealDB::printUpdatedList(const char fileName[]) {
    ofstream outFile(fileName);
    for (int index = 0; index < numCereal; index++) {
    cerealList[index].printCereal(outFile);
    }
}

int cerealDB::readCerealData(){
ifstream cerealFile("cereal.txt");
    numCereal = 0;
    while(cerealFile.peek() != EOF && numCereal < MAX_NUM_CEREALS) {
        cerealList[numCereal].readCereal(cerealFile);
        numCereal++;
    }
    return numCereal;
  }

void cerealDB::addCereal(){
      cerealList[numCereal].addCereal();
        numCereal++;
  }

void cerealDB::removeCereal(){
  int removeIndex = 0;
  do {
  removeIndex = readInt("Index to be removed: ");
    for(int index = removeIndex; index < numCereal - 1; index++){
    cerealList[index] = cerealList[index + 1];
  }
}
while(removeIndex < 0 && removeIndex >= 100);
}

void cerealDB::printbyCals(){
  for(int index = 0; index < numCereal; index++){
  if (cerealList[index].getnumCalories() <= 100){
      cerealList[index].printCereal(cout);
    }
    }
}

void cerealDB::Menu(){
  int input = 0;  
  while(input != 7) {
      cout << "Choose option." << endl;
      cout << "1. Load list" << endl;
      cout << "2. Print list" << endl;
      cout << "3. Add cereal" << endl;
      cout << "4. Remove cereal" << endl;
      cout << "5. Print cereals with less than a specific amount of cals." << endl;
      cout << "6. Save list" << endl;
      cout << "7. Quit" << endl;
      cin >> input;

    if(input == 1){
    numCereal = readCerealData();
    }
    if(input == 2){
    printList();  
    }
    if(input == 3){
      if(numCereal <= 100){
        addCereal();
        numCereal++;
        }
      else{
        cout << "Database is full" << endl;
        }
    }
    if(input == 4){
    removeCereal();  
      numCereal--;
    }
    if(input == 5){
    printbyCals();  
    }
    if(input == 6){
    printUpdatedList("cereal1.txt");  
    }
    if(input == 7){
      cout << "You quit.";
      break;
        }
}
  }