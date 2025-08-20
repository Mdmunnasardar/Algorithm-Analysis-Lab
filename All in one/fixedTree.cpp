#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

int preIndex = 0;

Node* build(vector<int>& preorder, vector<int>& inorder, int inL, int inR) {
    if (inL > inR) return NULL;

    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);

    int mid = inL;
    while (mid <= inR && inorder[mid] != rootVal) mid++;  // find root in inorder

    root->left  = build(preorder, inorder, inL, mid - 1);
    root->right = build(preorder, inorder, mid + 1, inR);

    return root;
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
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

    preIndex = 0;
    Node* root = build(preorder, inorder, 0, n - 1);

    cout << "Postorder traversal: ";
    postorder(root);
    cout << "\n";
}
