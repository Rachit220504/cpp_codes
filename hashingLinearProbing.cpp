#include <iostream>
using namespace std;
#define size 11

struct hashing {
    int key;
};

struct hashing hashTable[size];

void print() {
    for (int i = 0; i < size; i++) {
        cout << hashTable[i].key << " ";
    }
}

void initializing() {
    for (int i = 0; i < size; i++) {
        hashTable[i].key = -1;
    }
}

int findindex(int key) {
    return key % size;
}

void insert(int key) {
    int ind = findindex(key);

    while (hashTable[ind].key != -1) {
        ind = (ind + 1) % size;
    }
    hashTable[ind].key = key;
}

int main() {
    initializing();
    for (int i = 0; i < size; i++) {
        int key;
        cout << "Enter key:";
        cin >> key;
        insert(key);
    }
    cout << "Hash table: ";
    print();
    return 0;
}
