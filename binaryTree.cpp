#include <iostream>
using namespace std;

// Define the binary tree node struct
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node with the given data
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Function to insert a new node into the binary tree
Node* insert(Node* node, int data) {
    if (node == nullptr) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to print the binary tree in-order
void printInOrder(Node* node) {
    if (node != nullptr) {
        printInOrder(node->left);
        cout << node->data << " ";
        printInOrder(node->right);
    }
}

int main() {
    // Create the binary tree
    Node* root = nullptr;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    // Print the binary tree in-order
    cout << "In-order traversal: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
