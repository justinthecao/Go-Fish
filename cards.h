//cards.h
//Authors: Justin Cao
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include <iostream>
using namespace std;

class cards{
    private:
        int suit;
        int value;
    public: 
        cards(string line);
        cards():suit(0), value(0){}
        // a print function
        void print();

        bool operator==(const cards& a);
        bool operator<(const cards& a);
        bool operator>(const cards& a);
};

class cardBST{
    public: 
        cardBST():root(nullptr){}
        ~cardBST();
        bool insert(cards& c); //done
        bool find(cards& c) const;
        cards& getPredecessor(cards& c) const;
        cards& getSuccessor(cards& c) const;
        void printInOrder() const;
        bool remove(cards& c);
        cards& getMax() const;
        cards& getMin() const;
        void playGame(cardBST& a);
        void printPostOrder() const {
            printPostOrder(root);
        }
        void printPreOrder() const {
            printPreOrder(root);
        }
        
        // recursive helper for printPreOrder()
        

        
    private:
        class Node{
            public:
                cards elem;
                Node* left;
                Node* right;
                Node* parent;
                
                Node(const cards& p){
                    elem = p;
                    left = nullptr;
                    right = nullptr;
                    parent = nullptr;
                }
            
        };

        Node* root;
        void clear(Node* n);
        bool insert(cards& c, Node* n); //inserts Node into BST
        Node* getNodeFor(cards& s, Node* n) const; //returns node if node with card is found
        Node* getPredecessorNode(cards& c) const;
        Node* getSuccessorNode(cards& c) const;
        void printInOrder(Node* n) const;
        Node* getMaxNode() const;
        Node* getMinNode() const;
        bool removeA(Node* min, cardBST& a);
        bool removeB(Node* max, cardBST& a);
        void printPostOrder(Node *n) const {
            if(!n) return;
            printPostOrder(n->left);
            printPostOrder(n->right);
            n->elem.print();
            
        }
        void printPreOrder(Node *n) const {
            if (n) {
            n->elem.print();
            printPreOrder(n->left);
            printPreOrder(n->right);
            }
        }

};

#endif