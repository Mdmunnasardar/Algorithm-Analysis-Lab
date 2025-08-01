#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() : root(nullptr) {}

    void insertLevelOrder(int value) {
        Node* newNode = new Node(value);
        if (!root) {
            root = newNode;
            return;
        }
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left) {
                temp->left = newNode;
                return;
            } else {
                q.push(temp->left);
            }

            if (!temp->right) {
                temp->right = newNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }

    void inorderTraversal(Node* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    // Insert nodes level-wise
    tree.insertLevelOrder(1);
    tree.insertLevelOrder(2);
    tree.insertLevelOrder(3);
    tree.insertLevelOrder(4);
    tree.insertLevelOrder(5);
    tree.insertLevelOrder(6);

    cout << "Inorder traversal: ";
    tree.inorder();

    return 0;
}
