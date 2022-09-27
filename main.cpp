#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  
  cardBST deckA;
  while (getline (cardFile1, line) && (line.length() > 0)){
      cards a(line);
      deckA.insert(a);
  }
  cardFile1.close();

  cardBST deckB;
  while (getline (cardFile2, line) && (line.length() > 0)){
      cards a(line);
      deckB.insert(a);
  }
  cardFile2.close();
  deckA.playGame(deckB);
  


  
  return 0;
}
