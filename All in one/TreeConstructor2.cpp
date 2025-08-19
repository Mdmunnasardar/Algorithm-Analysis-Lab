#include <iostream>
#include <vector>
using namespace std;

// Tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int preIndex = 0;  // global index for preorder

// Recursive function to build tree
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    // Pick current node from preorder
    TreeNode* root = new TreeNode(preorder[preIndex++]);

    // If the node has no children
    if (inStart == inEnd) return root;

    // Find index of root in inorder
    int inIndex;
    for (inIndex = inStart; inIndex <= inEnd; inIndex++) {
        if (inorder[inIndex] == root->val) break;
    }

    // Build left and right subtrees
    root->left = buildTree(preorder, inorder, inStart, inIndex - 1);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd);

    return root;
}

// Postorder traversal (for checking)
void printPostorder(TreeNode* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> preorder(n), inorder(n);

    cout << "Enter preorder sequence: ";
    for (int i = 0; i < n; i++) cin >> preorder[i];

    cout << "Enter inorder sequence: ";
    for (int i = 0; i < n; i++) cin >> inorder[i];

    preIndex = 0; // reset global index
    TreeNode* root = buildTree(preorder, inorder, 0, n - 1);

    cout << "Postorder traversal of constructed tree: ";
    printPostorder(root);
    cout << endl;

    return 0;
}
