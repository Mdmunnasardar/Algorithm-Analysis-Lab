#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* Insertion(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {          
            node->left = Insertion(node->left, value);
        }
        else if (value > node->data) {      
            node->right = Insertion(node->right, value);
        }
        return node;
    }

    void InorderTraversal(Node* node) {
        if (node != nullptr) {
            InorderTraversal(node->left);
            cout << node->data << " ";
            InorderTraversal(node->right);
        }
    }

    void PreorderTraversal(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            PreorderTraversal(node->left);
            PreorderTraversal(node->right);
        }
    }

    void PostorderTraversal(Node* node) {
        if (node != nullptr) {
            PostorderTraversal(node->left);
            PostorderTraversal(node->right);
            cout << node->data << " ";
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = Insertion(root, value);
    }

    void inorder() {
        InorderTraversal(root);
        cout << endl;
    }

    void preorder() {
        PreorderTraversal(root);
        cout << endl;
    }

    void postorder() {
        PostorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(40);
    bst.insert(30);
    bst.insert(20);

    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Preorder traversal: ";
    bst.preorder();

    cout << "Postorder traversal: ";
    bst.postorder();
    return 0;
}
