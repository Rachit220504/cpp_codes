#include <iostream>
using namespace std;
#define size 11

struct hashing {
    int key;
};

struct hashing hashTable[size];

void initialising() {
    for (int i = 0; i < size; i++) {
        hashTable[i].key = -1;
    }
}

void print() {
    for (int i = 0; i < size; i++) {
        cout << hashTable[i].key << " ";
    }
}

int getIndex(int key) {
    return key % size;
}

void insert(int key) {
    int index = getIndex(key);
    int i = 1;
    int newIndex = index;
    while (hashTable[newIndex].key != -1) {
        newIndex = (index + i * i) % size;
        i++;
    }
    hashTable[newIndex].key = key;
}

int main() {
    initialising();
    for (int i = 0; i < size; i++) {
        cout << "Enter key: ";
        int a;
        cin >> a;
        insert(a);
    }
    cout << "Hash table: ";
    print();
    return 0;
}
