#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true; // empty tree is valid
        if (node->val <= minVal || node->val >= maxVal) return false;
        return helper(node->left, minVal, node->val) &&
               helper(node->right, node->val, maxVal);
    }
};

// ✅ Helper to build tree from input
TreeNode* buildTree(vector<string>& nodes, int index) {
    if (index >= nodes.size() || nodes[index] == "null") return NULL;
    TreeNode* root = new TreeNode(stoi(nodes[index]));
    root->left = buildTree(nodes, 2 * index + 1);
    root->right = buildTree(nodes, 2 * index + 2);
    return root;
}

int main() {
    cout << "Enter tree in level-order (use 'null' for empty):\n";
    // Example input: 5 1 4 null null 3 6
    vector<string> nodes;
    string s;
    while (cin >> s) {
        nodes.push_back(s);
        if (cin.peek() == '\n') break;
    }

    TreeNode* root = buildTree(nodes, 0);

    Solution sol;
    if (sol.isValidBST(root))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
