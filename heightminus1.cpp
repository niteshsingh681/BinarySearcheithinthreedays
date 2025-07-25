# include <iostream>
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
    int height1(Node* node) {
       if(!node) return 0;// Base case: if the node is null,  return -1;so that 1+(-1,-1) = 0;
       int lh=height1(node->left);
       int rh=height1(node->right);
       return 1+max(lh,rh);
        
    }
    int height(Node*node){
        int ht=height1(node)-1;
        return ht ;
    }
};

 int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    cout << "Height of the tree minus 1: " << sol.height(root) << endl;

    return 0;
}