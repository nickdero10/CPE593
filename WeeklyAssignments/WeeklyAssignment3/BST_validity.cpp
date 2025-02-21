/*
Author: Nicholas DeRobertis
I Pledge my Honor that I have Abided by the Stevens Honor System
Weekly Assignment 3: Trees
*/


#include <iostream>
#include <sstream>
#include <queue>
#include <climits>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Class to check if a tree is a valid BST
class Solution {
public:
    bool isValidBST(Node *root) {
        // Uses long so no overflow happens during recursion
        return Valid(root, LONG_MIN, LONG_MAX);
    }

private:
    // Function that recursivley checks the BST validty
    bool Valid(Node* node, long min, long max){
        // An empty tree is a valid BST
        if (!node) {
            return true;
        }

        // Checks that current value is not lower or higher than the max or min values from higher levels in the tree
        if (node -> data <= min || node -> data >= max) {
            return false;
        }

        /*
        Checks the left and rigth subtrees of the current node to see that
        1. The left subtree is lower than the current value
        2. The right subtree is higher than the current value
        */
        return Valid(node -> left, min, node -> data) &&
                Valid(node -> right, node -> data, max);
    }

};

// Function to create a binary tree from a space-separated string of node values
Node* createTreeFromInput(const string& input) {
    stringstream ss(input);
    int value;
    ss >> value;

    if (value == -1) return NULL;  // If the root is -1, return NULL

    Node* root = new Node(value);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        // Left child
        if (ss >> value) {
            if (value != -1) {
                current->left = new Node(value);
                q.push(current->left);
            }
        }

        // Right child
        if (ss >> value) {
            if (value != -1) {
                current->right = new Node(value);
                q.push(current->right);
            }
        }
    }

    return root;
}

// Main function
int main() {
    Solution solution;

    cout << "Enter tree values in level order (space-separated), use -1 for NULL nodes:\n";
    string input;
    getline(cin, input);  // Take a whole line of input

    Node* root = createTreeFromInput(input);

    // Check if the tree is a valid BST
    if (solution.isValidBST(root)) {
        cout << "The tree is a valid BST.\n";
    } else {
        cout << "The tree is NOT a valid BST.\n";
    }

    return 0;
}
