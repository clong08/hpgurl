//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : JYour name
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);
void displayBid(Bid bid);

// define a structure to hold bid information
struct Bid {
        string bidId; // unique identifier
        string title;
        string fund;
        double amount;

        Bid() {
                amount = 0.0;
        }
};

// FIXME (1): Internal structure for tree node
struct Node {
        Bid data;
        Node *left, *right;

        Node(Bid d) {
                data = d;
        }
};

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
* Define a class containing data members and methods to
* implement a binary search tree
*/
class BinarySearchTree {

        private:
        Node* root;

        void addNode(Node* node, Bid bid);
        void inOrder(Node* node);
        Node* removeNode(Node* node, string bidId);

        public:
        BinarySearchTree();
        virtual ~BinarySearchTree();
        void InOrder();
        void Insert(Bid bid);
        void Remove(string bidId);
        Bid Search(string bidId);
};

/**
* Default constructor
*/
BinarySearchTree::BinarySearchTree() {
        root = NULL;
}

void freeNode(Node *x) {
        if(x->left) {
                freeNode(x->left);
        }if(x->right) {
                freeNode(x->right);
        }
        delete x;
}
/**
* Destructor
*/
BinarySearchTree::~BinarySearchTree() {
        freeNode(root);
}

/**
* Traverse the tree in order
*/
void BinarySearchTree::InOrder() {
        inOrder(root);
}

void insertNode(Node *root, Node *newNode) {
}
/**
* Insert a bid
*/
void BinarySearchTree::Insert(Bid bid) {
        if(root == NULL) {
                Node *newBid = new Node(bid);
                newBid->left = NULL;
                newBid->right = NULL;
                root = newBid;
        } else {
                insertNode(root, bid);
        }
}

/**
* Remove a bid
*/
void BinarySearchTree::Remove(string bidId) {
// FIXME (4a) Implement removing a bid from the tree
}

/**
* Search for a bid
*/
Bid BinarySearchTree::Search(string bidId) {
// FIXME (3) Implement searching the tree for a bid

        if(root == NULL) {
               return false;
        } else {
                Node *start = root;
                while(start != NULL) {
                        if(start->data->bidId == bidId) {
                                return true;
                        }
                        if(start->data->bidId < bidId) {
                                start = start->right;
                        } else {
                                start = start->left;
                        }
                }
                return false;
        }
}

/**
* Add a bid to some node (recursive)
*
* @param node Current node in tree
* @param bid Bid to be added
*/
void BinarySearchTree::addNode(Node* node, Bid bid) {
// FIXME (2b) Implement inserting a bid into the tree
        if(node->data->bidId < newNode->data->bidId) {
                if(node->left) {
                        insertNode(node->left, bid);
                } else {
                        Node *newBid = new Node(bid);
                        newBid->left = NULL;
                        newBid->right = NULL;
                        node->left = newNode;
                }
        } else {
                if(node->right) {
                        insertNode(node->right, bid);
                } else {
                        Node *newBid = new Node(bid);
                        newBid->left = NULL;
                        newBid->right = NULL;
                        node->right = newNode;
                }
        }
}
void BinarySearchTree::inOrder(Node* node) {
        if(node == NULL) {
                return;
        }
        inOrder(node->left);
        displayBid(node->data);
        inOrder(node->right);
}
//============================================================================
// Static methods used for testing
//============================================================================

/**
* Display the bid information to the console (std::out)
*
* @param bid struct containing the bid info
*/
void displayBid(Bid bid) {
        cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
        << bid.fund << endl;
        return;
}

/**
* Load a CSV file containing bids into a container
*
* @param csvPath the path to the CSV file to load
* @return a container holding all the bids read
*/
void loadBids(string csvPath, BinarySearchTree* bst) {
        cout << "Loading CSV file " << csvPath << endl;

        // initialize the CSV Parser using the given path
        csv::Parser file = csv::Parser(csvPath);

        // read and display header row - optional
        vector<string> header = file.getHeader();
        for (auto const& c : header) {
        cout << c << " | ";
        }
        cout << "" << endl;

        try {
                // loop to read rows of a CSV file
                for (unsigned int i = 0; i < file.rowCount(); i++) {

                        // Create a data structure and add to the collection of bids
                        Bid bid;
                        bid.bidId = file[i][1];
                        bid.title = file[i][0];
                        bid.fund = file[i][8];
                        bid.amount = strToDouble(file[i][4], '$');

                        //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

                        // push this bid to the end
                        bst->Insert(bid);
                }
        } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
        }
}

/**
* Simple C function to convert a string to a double
* after stripping out unwanted char
*
* credit: http://stackoverflow.com/a/24875936
*
* @param ch The character to strip out
*/
double strToDouble(string str, char ch) {
        str.erase(remove(str.begin(), str.end(), ch), str.end());
        return atof(str.c_str());
}

/**
* The one and only main() method
*/
int main(int argc, char* argv[]) {

// process command line arguments
string csvPath, bidKey;
switch (argc) {
case 2:
csvPath = argv[1];
bidKey = "98109";
break;
case 3:
csvPath = argv[1];
bidKey = argv[2];
break;
default:
csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
bidKey = "98109";
}

// Define a timer variable
clock_t ticks;

// Define a binary search tree to hold all bids
BinarySearchTree* bst;

Bid bid;

int choice = 0;
while (choice != 9) {
cout << "Menu:" << endl;
cout << " 1. Load Bids" << endl;
cout << " 2. Display All Bids" << endl;
cout << " 3. Find Bid" << endl;
cout << " 4. Remove Bid" << endl;
cout << " 9. Exit" << endl;
cout << "Enter choice: ";
cin >> choice;

switch (choice) {

case 1:
bst = new BinarySearchTree();

// Initialize a timer variable before loading bids
ticks = clock();

// Complete the method call to load the bids
loadBids(csvPath, bst);

//cout << bst->Size() << " bids read" << endl;

// Calculate elapsed time and display result
ticks = clock() - ticks; // current clock ticks minus starting clock ticks
cout << "time: " << ticks << " clock ticks" << endl;
cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
break;

case 2:
bst->InOrder();
break;

case 3:
ticks = clock();

bid = bst->Search(bidKey);

ticks = clock() - ticks; // current clock ticks minus starting clock ticks

if (!bid.bidId.empty()) {
displayBid(bid);
} else {
   cout << "Bid Id " << bidKey << " not found." << endl;
}

cout << "time: " << ticks << " clock ticks" << endl;
cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

break;

case 4:
bst->Remove(bidKey);
break;
}
}

cout << "Good bye." << endl;

   return 0;
}
