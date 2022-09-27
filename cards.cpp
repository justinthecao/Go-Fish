//cards.cpp
//Authors: Justin Cao
//Implementation of the classes defined in cards.h
//Should contain implementation of the binary search tree to store a list of cards
#include "cards.h"
#include <iostream>
using namespace std;

//cards constructor from the files
cards::cards(string line){
    char s = line.at(0);
    string v = line.substr(2,-1);
    if(s == 'c'){
        suit = 1;
    }
    else if(s == 'd'){
        suit = 2;
    }
    else if(s == 's'){
        suit = 3;
    }
    else{
        suit = 4;
    }
    if(v == "j"){
        value = 11;
    }
    else if(v == "q"){
        value = 12;
    }
    else if(v == "k"){
        value = 13;
    }
    else if(v == "a"){
        value = 1;
    }
    else{
        value = stoi(v);
    }
}

bool cards::operator==(const cards& a){
    if((suit == a.suit) && (value == a.value)){
        return true;
    }
    return false;
}

bool cards::operator<(const cards& a){
    if(suit == a.suit){                                                                  
        //if both cards are of same suit
        if(value < a.value){
            return true;
        }
        else{
            return false;
        }
    }
    else if (suit < a.suit){
        //if cards are of different suit
        return true;
    }
    else{
        return false;
    }
}

bool cards::operator>(const cards& a){
    if(suit == a.suit){                                                                  
        //if both cards are of same suit
        if(value > a.value){
            return true;
        }
        else{
            return false;
        }
    }
    else if(suit > a.suit){
        //if cards are of different suit
        return true;
    }
    else{
        return false;
    }
}

void cards::print(){
    if(suit == 0){
        cout << "none";
    }
    else{
        if(suit == 1){
            cout << "c ";
        }
        else if(suit == 2){
            cout << "d ";
        }
        else if(suit == 3){
            cout << "s ";
        }
        else{
            cout << "h ";
        }
        if(value == 1){
            cout << "a";
        }
        else if((value > 1) && (value < 11)){
            cout << value;
        }
        else if(value == 11){
            cout << "j";
        }
        else if(value == 12){
            cout << "q";
        }
        else{
            cout << "k";
        }
    }
    cout << endl;
}

cardBST::~cardBST(){
    clear(root);
    root = nullptr;
}
void cardBST::clear(Node* p){
    if(p){
        clear(p->left);
        clear(p->right);
        delete p;
    }
}

bool cardBST::insert(cards& c){
    //if there is no root make the root equal to first element
    if(!root){
        root = new Node(c);
        return true;
    }
    return insert(c, root);
}

bool cardBST::insert(cards& c, Node* n){
    if(c == n->elem){
        return false;
    }
    if(c < n->elem){
        if(n->left){
            return insert(c, n->left);
        }
        else{
            n->left = new Node(c);
            n->left->parent = n;
            return true;
        }
    }
    else{
        if(n->right){
            return insert(c, n->right);
        }
        else{
            n->right = new Node(c);
            n->right->parent = n;
            return true;
        }
    }
}

bool cardBST::find(cards& c) const{
    if(getNodeFor(c, root)){
        return true;
    }else{
        return false;
    }

}

cardBST::Node* cardBST::getNodeFor(cards& s, Node* n) const{
    // cout <<"get";
    if(!n){
        // cout << "close";
        return nullptr;
    }
    // s.print();
    // cout << "yessir";
    if(s == n->elem){
        return n;
    }
    else{
        if(s < n->elem){
            getNodeFor(s, n->left);
        }
        else{
            getNodeFor(s, n->right);
        }
    }
}

void cardBST::printInOrder() const{
    printInOrder(root);

}

void cardBST::printInOrder(Node *n) const{
    if(!n) return;
    printInOrder(n->left);
    n->elem.print();
    printInOrder(n->right);
}

cardBST::Node* cardBST::getPredecessorNode(cards& value) const{
    if(!root) return nullptr;
    Node* currNode = getNodeFor(value, root);
    Node* leftMost;
    for (leftMost = root; leftMost->left != 0; leftMost = leftMost->left){}
    if (value == leftMost->elem){
        return nullptr;
    }
    if (currNode->left != 0){
        Node* cursorNode = currNode->left;
        for (Node* cursor = currNode->left; cursor->right != 0; cursor = cursor->right){
            cursorNode = cursorNode->right;
        }
        return cursorNode;
    }
    else{
        
        if (currNode->parent->right == currNode){
            return currNode->parent;
        }
        else{
            Node* cursor = currNode;
            while(cursor->parent->elem > cursor->elem){
                cursor = cursor->parent;
            }
            return cursor->parent;
        }
    }
    
}

// returns the predecessor value of the given value or 0 if there is none
cards& cardBST::getPredecessor(cards& value) const{
    // cout << "pred";
    Node* predNode = getPredecessorNode(value);
    if (predNode){
        return predNode->elem;
    }
    else{
        cards* a = new cards();
        return *a;
    }
}

cards& cardBST::getSuccessor(cards& value) const{
    Node* succNode = getSuccessorNode(value);
    if(succNode){
        return succNode->elem;
    }
    else{
        cards* a = new cards();
        return *a;
    }
}

cardBST::Node* cardBST::getSuccessorNode(cards& value) const{
    // cout << "succ";
    if(!root) return nullptr;
    Node* currNode = getNodeFor(value, root);
    // currNode->elem.print();/
    Node* rightMost;
    for (rightMost = this->root; rightMost->right != 0; rightMost = rightMost->right){}
    
    //if value is the rightmost term of a bst
    if (value == rightMost->elem){
        return nullptr;
    }

    if (currNode->right != 0){
        // return right child's leftmost child
        Node* cursorNode;
        for (cursorNode = currNode->right; cursorNode->left != 0; cursorNode = cursorNode->left){
        }
        return cursorNode;
    }
    else{
        //if currNode has no right subtree and its the left child return the parent
        if (currNode->parent->left == currNode){
            return currNode->parent;
        }
        else{
            //if currNode has no right subtree and its the right child 
            Node* cursor = currNode;
            while(cursor->parent->elem < cursor->elem){
                cursor = cursor->parent;
            }
            return cursor->parent;
        }
    }
}

bool cardBST::remove(cards& value){
    // cout << "1";
    // value.print();
    if(!root){
        return false;
    }
    Node* pointer = getNodeFor(value, root);
    // cout << "1.1";
    // pointer->elem.print();
    if(!pointer){
        return false;
    }
    // cout << "2";
    // pointer->elem.print();
    //if the pointer is leaf, remove pointer and set corresponding branch on parent to 0 
    if(!(pointer->right) && !(pointer->left)){
        // cout << "3";
        // pointer->elem.print();

        if(pointer == root){
            // cout << "3.1";
            // pointer->elem.print();

            delete pointer;
            root = nullptr;
            return true;
        }
        if(pointer->parent->right == pointer){
            // cout << "3.2";
            // pointer->elem.print();

            pointer->parent->right = nullptr;
        }
        else{
            // cout << "3.3";
            // pointer->elem.print();

            pointer->parent->left= nullptr;
        }
        delete pointer;
        // cout<< "3.4";
        // pointer->elem.print();

        return true;
    }
    //if pointer is branch with 1 child left or right
    //left:

    if((pointer->right) && !(pointer->left)){
        // cout << "4";
    // pointer->elem.print();
        if(pointer == root){
            
            root = pointer->right;
            delete pointer;
            return true;
        }
        //only has right child
         if(pointer == pointer->parent->right){
            // cout << "4.1";
    // pointer->elem.print();

            //if pointer is the right child of its parent
            pointer->parent->right = pointer->right;
            pointer->right->parent = pointer->parent;
        }
        else{
            // cout << "4.2";
    // pointer->elem.print();
            //if pointer is the left child of the parent
            pointer->parent->left = pointer->right;
            pointer->right->parent = pointer->parent;
        }
        delete pointer;
        // cout << "4.3";
        // pointer->elem.print();
        return true;
    }
    else if(pointer->left && !(pointer->right)){
        // cout << "5";
    // pointer->elem.print();
        if(pointer == root){
                root = pointer->left;
                delete pointer;
                return true;
        }
        //only has left child
        if(pointer==pointer->parent->left){
            //if the pointer is the the left child
            pointer->parent->left = pointer->left;
            pointer->left->parent = pointer->parent;
        }
        else{
            pointer->parent->right = pointer->left;
            pointer->left->parent = pointer->parent;
        }
        delete pointer;
        return true;
    }

    else{
        // cout << "6";
        // pointer->elem.print();
        Node* succNode = getSuccessorNode(pointer->elem);
        cards a = succNode->elem;
        // succNode->elem.print();
        remove(succNode->elem);
        pointer->elem = a;
        return true;
        //has both children

    }
}

cards& cardBST::getMax() const{
    Node* max = getMaxNode();
    if(max){
        return max->elem;
    }
    else{
        cards* zero = new cards();
        return *zero;
    }

}

cardBST::Node* cardBST::getMaxNode() const{
    if(!root) return nullptr;
    Node* p;
    for(p = root; p->right != nullptr; p= p->right){
    }
    return p;
}

cards& cardBST::getMin() const{
    Node* min = getMinNode();
    if(min){
        return min->elem;
    }
    else{
        return root->elem;
    }

}

cardBST::Node* cardBST::getMinNode() const{
    if(!root) return nullptr;
    Node* p;
    for(p = root; p->left != nullptr; p= p->left){
    }
    return p;
}

bool cardBST::removeA(Node* min, cardBST& a){
    // cout << "removA";
    // min->elem.print();
    // printInOrder();
    Node* travel = min;
    while(travel){
        if(a.find(travel->elem)){
            cout << "Alice picked matching card ";
            travel->elem.print();
            a.remove(travel->elem);
            remove(travel->elem);
            // printInOrder();
            // cout << endl;
            // a.printInOrder();
            return true;
        }

        travel = getSuccessorNode(travel->elem);
    }
    return false;
}


bool cardBST::removeB(Node* max, cardBST& a){
    // cout << "removB " ;
    Node* travel = max;
    while(travel){
        if(a.find(travel->elem)){
            cout << "Bob picked matching card ";
            travel->elem.print();
            a.remove(travel->elem);
            // travel->elem.print();
            remove(travel->elem);
            // travel->elem.print();
            return true;
        }
        travel = getPredecessorNode(travel->elem);
    }
    return false;
}

void cardBST::playGame(cardBST& b){
    bool removed = true;
    while(removed){
        removed = removeA(getMinNode(), b) && b.removeB(b.getMaxNode(), *this);
        // cout << "wow";
        // printInOrder();
        // cout  << endl;
        // b.printInOrder();
    }
    cout << endl;
    cout << "Alice's cards:" << endl;
    printInOrder();
    cout << endl << "Bob's cards:" << endl;
    b.printInOrder();
}