/* Should contain test code for all the classes and methods you used in 
    your game. Should have 5 test cases for each public member function
*/
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
  


  cards a("c a");
  cards b("h 9");
  cards c("c 7");
  cards d("h 9");
  cards e("s j");
  cards f("s 5");
  cards g("c 8");
  cards h("s 2");
  cards i("h 10");
  cards j("s j");
  deckA.printInOrder();
  cout << endl;
  deckA.getSuccessor(a).print();
  deckA.getSuccessor(b).print();
  deckA.getSuccessor(c).print();
  deckA.getSuccessor(d).print();
  deckA.getSuccessor(e).print();
  deckA.getSuccessor(f).print();
  deckA.getSuccessor(g).print();
  deckA.getSuccessor(h).print();
  deckA.getSuccessor(i).print();
  deckA.getSuccessor(j).print();


  
  // cout << "before" << endl;
  // deckA.printInOrder();
  //   deckA.remove(a);
  //   // deckB.remove(b);
  //   deckA.remove(c);
  //   cout << endl;
  // deckA.printInOrder();
  // cout << endl;
  // deckA.printPreOrder();
    // cardBST bst1, bst2;
    // cards a, b, c, d, e, f, g, h, i, j, k, z,y;
    // a = cards("h 3");
    // b = cards("s 10");
    // c = cards("c a");
    // d = cards("c 3");
    // e = cards("s 5");
    // f = cards("h 10");
    // g = cards("d a");

    // bst1.insert(a);
    // bst1.insert(b);
    // bst1.insert(c);
    // bst1.insert(d);
    // bst1.insert(e);
    // bst1.insert(f);
    // bst1.insert(g);

    // bst1.remove(a);

    // bst1.printPreOrder();
    
    /*
    a =  cards("d 7");
    b =  cards("c 4");
    c =  cards("s 5");
    d =  cards("h 4");
    e =  cards("c 8");
    f =  cards("s 6");
    g =  cards("h 10");
    h =  cards("s q");
    i =  cards("d 10");
    j =  cards("h j");
    k =  cards("d a");
    bst1.insert(a);
    bst1.insert(b);
    bst1.insert(c);
    bst1.insert(d);
    bst1.insert(e);
    bst1.insert(f);
    bst1.insert(g);
    bst1.insert(h);
    bst1.insert(i);
    bst1.insert(j);
    bst1.insert(k);
    z =  cards("h 3");
    y =  cards("s 4");
    //find tests
    cout << " contains d 7 " << (bst1.find(a) ? "Y" : "N") << endl;
    cout << " contains h 3 " << (bst1.find(z) ? "Y" : "N") << endl;
    cout << " contains c 8 " << (bst1.find(e) ? "Y" : "N") << endl;
    cout << " contains h j " << (bst1.find(j) ? "Y" : "N") << endl;
    cout << " contains s 4 " << (bst1.find(y) ? "Y" : "N") << endl;
    

    bst1.printInOrder();

    //getPredecessorTests
    cout << "predecessor of d 7 is" << endl; 
    bst1.getPredecessor(a).print();
    cout << "predecessor of s 5 is" << endl;
    bst1.getPredecessor(c).print();
    cout << "predecessor of h j is" << endl;
    bst1.getPredecessor(j).print();
    cout << "predecessor of s 6 is" << endl;
    bst1.getPredecessor(f).print();
    cout << "predecessor of h 10 is" << endl;
    bst1.getPredecessor(g).print();
    cout << "predecessor of c 4 is" << endl;
    bst1.getPredecessor(b).print();
    //getSuccessorTests
    cout << "successor of d 7 is" << endl; 
    bst1.getSuccessor(a).print();
    cout << "successor of s 5 is" << endl;
    bst1.getSuccessor(c).print();
    cout << "successor of h j is" << endl;
    bst1.getSuccessor(j).print();
    cout << "successor of s 6 is" << endl;
    bst1.getSuccessor(f).print();
    cout << "successor of h 10 is" << endl;
    bst1.getSuccessor(g).print();
    cout << "successor of c 4 is" << endl;
    bst1.getSuccessor(b).print();

    //remove tests
    cout << "removing d 7" << endl; 
    bst1.remove(a);
    cout << "this is the current max/min" << endl;
    bst1.getMax().print();
    cout << " ";
    bst1.getMin().print();
    cout << "removing s 5" << endl;
    bst1.remove(c);
    cout << "this is the current max/min" << endl;
    bst1.getMax().print();
    cout << " ";
    bst1.getMin().print();
    cout << "removing h j" << endl;
    bst1.remove(j);
    cout << "this is the current max/min" << endl;
    bst1.getMax().print();
    cout << " ";
    bst1.getMin().print();
    cout << "removing s 6" << endl;
    bst1.remove(f);
    cout << "this is the current max/min" << endl;
    bst1.getMax().print();
    cout << " ";
    bst1.getMin().print();
    cout << "removing h 10" << endl;
    bst1.remove(g);
    cout << "this is the current max/min" << endl;
    bst1.getMax().print();
    cout << " ";
    bst1.getMin().print();
    cout << "removing c 4" << endl;
    bst1.remove(b);
    cout << "this is the current max/min" << endl;
    bst1.getMax().print();
    cout << " ";
    bst1.getMin().print();

    bst1.printInOrder();
    
    

    */


    //bst2

    // cout << "BSTBSTBSTBSTBSTBSTBSTBSTBSTBSTBSTB" << endl;
    // cout << " contains d 7 " << (bst2.find(a) ? "Y" : "N") << endl;
    // cout << " contains h 3 " << (bst2.find(z) ? "Y" : "N") << endl;
    // cout << " contains c 8 " << (bst2.find(e) ? "Y" : "N") << endl;
    // cout << " contains h j " << (bst2.find(j) ? "Y" : "N") << endl;
    // cout << " contains s 4 " << (bst2.find(y) ? "Y" : "N") << endl;


    // bst2.printInOrder();

    // //getPredecessorTests
    // cout << "predecessor of d 7 is" << endl; 
    // bst2.getPredecessor(a).print();
    // cout << "predecessor of s 5 is" << endl;
    // bst2.getPredecessor(c).print();
    // cout << "predecessor of h j is" << endl;
    // bst2.getPredecessor(j).print();
    // cout << "predecessor of s 6 is" << endl;
    // bst2.getPredecessor(f).print();
    // cout << "predecessor of h 10 is" << endl;
    // bst2.getPredecessor(g).print();
    // cout << "predecessor of c 4 is" << endl;
    // bst2.getPredecessor(b).print();
    // //getSuccessorTests
    // cout << "successor of d 7 is" << endl; 
    // bst2.getSuccessor(a).print();
    // cout << "successor of s 5 is" << endl;
    // bst2.getSuccessor(c).print();
    // cout << "successor of h j is" << endl;
    // bst2.getSuccessor(j).print();
    // cout << "successor of s 6 is" << endl;
    // bst2.getSuccessor(f).print();
    // cout << "successor of h 10 is" << endl;
    // bst2.getSuccessor(g).print();
    // cout << "successor of c 4 is" << endl;
    // bst2.getSuccessor(b).print();
    // //remove tests
    // cout << "removing d 7" << endl; 
    // bst2.remove(a);
    // bst2.printInOrder();

    // cout << "this is the current max" << endl;
    // bst2.getMax().print();
    // cout << "removing s 5" << endl;
    // bst2.remove(c);
    // bst2.printInOrder();

    // cout << "this is the current max" << endl;
    // bst2.getMax().print();
    // cout << "removing h j" << endl;
    // bst2.remove(j);
    // bst2.printInOrder();

    // cout << "this is the current max" << endl;
    // bst2.getMax().print();
    // cout << "removing s 6" << endl;
    // bst2.remove(f);
    // bst2.printInOrder();

    // cout << "this is the current max" << endl;
    // bst2.getMax().print();

    // bst2.printInOrder();

    // cout << "removing h 10" << endl;
    // bst2.remove(g);
    // bst2.printInOrder();

    // cout << "this is the current max" << endl;
    // bst2.getMax().print();
    // cout << "removing c 4" << endl;
    // bst2.remove(b);
    // bst2.printInOrder();

    // cout << "this is the current max" << endl;
    // bst2.getMax().print();

    // bst2.printInOrder();

    

    

    
}