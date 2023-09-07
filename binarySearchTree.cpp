#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int arr[100];
int i = 0;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* NEWNODE = new Node;
    NEWNODE->data = data;
    NEWNODE->left = NULL;
    NEWNODE->right = NULL;
    return NEWNODE;
}

Node* createTree(Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data > root->data) {
        root->right = createTree(root->right, data);
    }
    else if (data < root->data) {
        root->left = createTree(root->left, data);
    }
    return root;
}

void preOrSuc(Node* root) {
    if (root != NULL) {
        preOrSuc(root->left);
        arr[i] = root->data;
        i++;
        preOrSuc(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = NULL;
    int n;
    cout << "Enter number of elements to be inserted: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cout << "Enter element to be inserted: ";
        cin >> a;
        root = createTree(root, a);
    }
    while (true) {
        cout << "1. Preorder" << endl;
        cout << "2. Inorder" << endl;
        cout << "3. Postorder" << endl;
        cout << "4. Successor" << endl;
        cout << "5. Predecessor" << endl;
        cout << "6. Height" << endl;
        cout << "7. Exit" << endl;
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            preOrder(root);
            cout << endl;
            break;
        case 2:
            inOrder(root);
            cout << endl;
            break;
        case 3:
            postOrder(root);
            cout << endl;
            break;
        case 4: {
            preOrSuc(root);
            int x, index;
            cout << "Enter element of which successor you want: ";
            cin >> x;
            for (int i = 0; i < n; i++) {
                if (arr[i] == x) {
                    index = i;
                    break;
                }
            }
            if (index == n - 1) {
                cout << "No Successor" << endl;
            }
            else {
                cout << "Successor of " << x << " is " << arr[index + 1] << "." << endl;
            }
            break;
        }
        case 5: {
            int y, index;
            cout << "Enter element of which predecessor you want: ";
            cin >> y;
            for (int i = 0; i < n; i++) {
                if (arr[i] == y) {
                    index = i;
                    break;
                }
            }
            if (index == 0) {
                cout << "No predecessor." << endl;
            }
            else {
                cout << "Predecessor of " << y << " is " << arr[index - 1] << "." << endl;
            }
            break;
        }
        case 6: {
            int h = ceil(log2(n + 1)) - 1;
            cout << "Height of tree = " << h << "." << endl;
            break;
        }
        case 7:
            return 0;
        default:
            cout << "Invalid Choice." << endl;
        }
    }
    return 0;
}
