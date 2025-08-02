# include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Node {
public: 
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
  public:
    bool isIdentical(Node* root1, Node* root2) {
        // Base case: both nodes are null
        if (!root1 && !root2) return true;
        
        // If one of the nodes is null, trees are not identical
        if (!root1 || !root2) return false;
        
        // Check current node's data and recursively check left and right subtrees
        return (root1->data == root2->data) &&
               isIdentical(root1->left, root2->left) &&
               isIdentical(root1->right, root2->right);
    }
};
class Solution2{
  public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        if((!r1 && r2)||(!r2 && r1)) return false;
        if(!r1 && !r2) return true;
        if(r1->data!=r2->data) return false;
        return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
    }
};
int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    Solution sol;
    if (sol.isIdentical(root1, root2)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }

    return 0;
}