#include <iostream>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* buildFromPreIn(int preorder[], int inorder[], int length) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < length; ++i)
        inMap[inorder[i]] = i;

    int preIndex = 0;
    function<TreeNode*(int, int)> build = [&](int inStart, int inEnd) -> TreeNode* {
        if (inStart > inEnd) return nullptr;
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int inIndex = inMap[rootVal];
        root->left = build(inStart, inIndex - 1);
        root->right = build(inIndex + 1, inEnd);
        return root;
    };

    return build(0, length - 1);
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

int main() {
    int preorder[] = {1, 2, 4, 5, 3, 6};
    int inorder[]  = {4, 2, 5, 1, 6, 3};
    int length = sizeof(preorder) / sizeof(preorder[0]);

    TreeNode* root = buildFromPreIn(preorder, inorder, length);

    printLevelOrder(root);
    return 0;
}