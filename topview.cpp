#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> result;
        if (!root) return result;

        map<int, int> hdMap;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
           Node* node = q.front().first;
int hd = q.front().second;

            q.pop();

            if (hdMap.find(hd) == hdMap.end())
                hdMap[hd] = node->data;

            if (node->left)  q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        for (auto it : hdMap) {
            result.push_back(it.second);
        }

        return result;
    }
};

// Helper to build a sample tree
Node* buildSampleTree() {
    /*
              1
            /   \
           2     3
            \   / \
             4 5   6
    Top View: 2 1 3 6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    return root;
}

int main() {
    Node* root = buildSampleTree();

    Solution sol;
    vector<int> top = sol.topView(root);

    cout << "Top View: ";
    for (int val : top) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
