#include <iostream>
#include <cstdlib>
using namespace std;

#define size 11

struct Node {
    int data;
    Node* next;
};

Node* hashTable[size];

void print() {
    for (int i = 0; i < size; i++) {
        Node* t = hashTable[i];
        if (t == nullptr) {
            cout << "-\n";
        } else {
            while (t != nullptr) {
                cout << t->data << " ";
                t = t->next;
            }
            cout << endl;
        }
    }
}

Node* insert(Node* head, Node* newnode) {
    newnode->next = head;
    head = newnode;
    return head;
}

void create(int key) {
    Node* newNode = new Node();
    newNode->data = key;
    newNode->next = nullptr;
    int index = key % size;
    if (hashTable[index] == nullptr) {
        hashTable[index] = newNode;
    } else {
        hashTable[index] = insert(hashTable[index], newNode);
    }
}

int main() {
    for (int i = 0; i < size; i++) {
        cout << "Enter key: ";
        int a;
        cin >> a;
        create(a);
    }
    cout << "Hash table:\n";
    print();
    return 0;
}
