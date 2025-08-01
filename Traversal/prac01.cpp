#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Insert into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

// Build BST from preorder
TreeNode* buildBSTFromPreorder(int preorder[], int n) {
    TreeNode* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insertBST(root, preorder[i]);
    }
    return root;
}

// Traversals
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printPostorder(TreeNode* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

// Main
int main() {
    int preorder[] = {8, 5, 1, 7, 10, 12};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    TreeNode* root = buildBSTFromPreorder(preorder, n);

    cout << "Preorder: ";
    printPreorder(root);
    cout << "\nInorder: ";
    printInorder(root);
    cout << "\nPostorder: ";
    printPostorder(root);
    cout << endl;

    return 0;
}
