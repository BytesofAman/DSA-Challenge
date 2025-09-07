#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }
};

// Helper function to find node by value
TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return NULL;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    unordered_map<int, TreeNode*> nodes;

    cout << "Enter nodes as: value left_child right_child (-1 if NULL)\n";
    int val, l, r;
    for (int i = 0; i < n; i++) {
        cin >> val >> l >> r;
        if (!nodes[val]) nodes[val] = new TreeNode(val);
        if (l != -1) {
            if (!nodes[l]) nodes[l] = new TreeNode(l);
            nodes[val]->left = nodes[l];
        }
        if (r != -1) {
            if (!nodes[r]) nodes[r] = new TreeNode(r);
            nodes[val]->right = nodes[r];
        }
    }

    int rootVal;
    cout << "Enter root value: ";
    cin >> rootVal;
    TreeNode* root = nodes[rootVal];

    int pVal, qVal;
    cout << "Enter p and q values: ";
    cin >> pVal >> qVal;

    TreeNode* p = findNode(root, pVal);
    TreeNode* q = findNode(root, qVal);

    Solution sol;
    TreeNode* ans = sol.lowestCommonAncestor(root, p, q);

    if (ans)
        cout << "LCA of " << pVal << " and " << qVal << " is: " << ans->val << endl;
    else
        cout << "LCA not found!" << endl;

    return 0;
}
