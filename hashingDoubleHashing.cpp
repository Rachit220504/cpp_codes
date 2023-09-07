#include <iostream>
using namespace std;
#define size 11
#define m 7

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

void insert(int key) {
    int h1 = key % size;
    int h2, newpos, i = 1;
    if (hashTable[h1].key == -1) {
        hashTable[h1].key = key;
        return;
    } else {
        h2 = 1 + (key % m);
        newpos = h1;
        while (hashTable[newpos].key != -1) {
            newpos = (h1 + i * h2) % size;
            i++;
        }
    }
    hashTable[newpos].key = key;
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
