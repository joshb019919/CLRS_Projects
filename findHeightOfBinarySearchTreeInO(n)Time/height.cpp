#include <iostream>
using namespace std;

class Node {
    public:
    int key;
    Node* left;
    Node* right;

    Node(): key(0), left(nullptr), right(nullptr) {}
    Node(int k): key(k), left(nullptr), right(nullptr) {}
};

class Tree {
    public:
    Node* root;

    Tree(): root(nullptr) {}

    int findHeight(Node* subRoot) {
        if (subRoot == nullptr) {
            return -1;
        }

        int leftHeight = findHeight(subRoot->left);
        int rightHeight = findHeight(subRoot->right);
        return (leftHeight > rightHeight) ? leftHeight+1 : rightHeight+1;
    }
};

int main() {
    // Empty
    Tree* t = new Tree();

    // Height of -1
    cout << t->findHeight(t->root) << endl;

    // root
    Node* root = new Node(1);
    t->root = root;

    // Height of 0
    cout << t->findHeight(t->root) << endl;

    //      root
    //     /    \
    // left      right
    Node* ltree = new Node(2);
    Node* rtree = new Node(3);
    ltree->key = 2;
    rtree->key = 3;
    root->key = 1;
    root->left = ltree;
    root->right = rtree;

    // Height of 1
    cout << t->findHeight(t->root) << endl;
    
    
    //            root
    //           /    \
    //       left      right
    //      /         /     \
    //  left      left       right
    //                            \
    //                             right
    Node* ltree2 = new Node(4);
    Node* rtree2 = new Node(5);
    Node* ltree3 = new Node(6);
    Node* rtree3 = new Node(7);
    ltree->left = ltree2;
    rtree->left = ltree3;
    rtree->right = rtree2;
    rtree2->right = rtree3;

    // Height of 3
    cout << t->findHeight(t->root) << endl;
    
    
    //            root
    //           /    \
    //       left      right
    //       /        /     \
    //  left2    left3       right2
    //                      /      \
    //                 left4        right3
    //                      \
    //                       right4
    //                      /
    //                 left5
    //                      \
    //                       right5
    Node* ltree4 = new Node(4);
    Node* rtree4 = new Node(5);
    Node* ltree5 = new Node(6);
    Node* rtree5 = new Node(7);
    rtree3->left = ltree4;
    ltree4->right = rtree4;
    rtree4->left = ltree5;
    rtree5->right = rtree5;

    // Height of 6
    cout << t->findHeight(t->root) << endl;

    delete ltree;
    delete rtree;
    delete root;
    delete t;

    return 0;
}