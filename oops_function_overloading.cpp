//Rachit Chandekar cs22b1088
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // insert a node at the beginning
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // insert a node at a specific position
    void insert(int data, int position) {
        if (position < 1) {
            cout << "Invalid position for insertion.\n";
            return;
        }

        Node* newNode = new Node(data);

        if (position == 1) {
            insert(data); // Insert at the beginning
        } else {
            Node* temp = head;
            int count = 1;
            while (temp->next != head && count < position - 1) {
                temp = temp->next;
                count++;
            }
            if (count < position - 1) {
                cout << "Invalid position for insertion.\n";
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }


    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty. Deletion failed.\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        do {
            if (temp->data == value) {
                if (prev == nullptr) {
                    // Deleting head node
                    Node* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Deleted node with value " << value << "\n";
                return;
            }

            prev = temp;
            temp = temp->next;

        } while (temp != head);

        cout << "Node with value " << value << " not found.\n";
    }

    bool search(int value) {
        if (head == nullptr) {
            return false;
        }

        Node* temp = head;

        do {
            if (temp->data == value) {
                return true;
            }

            temp = temp->next;

        } while (temp != head);

        return false;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << "\n";
    }
};

int main() {
    CircularLinkedList cl;
    int choice;
    int value, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position (1 for beginning, -1 for end, other for specific): ";
                cin >> position;
                if (position == -1) {
                    cl.insert(value);
                } else {
                    cl.insert(value, position);
                }
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                cl.deleteNode(value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (cl.search(value)) {
                    cout << "Value " << value << " found in the list.\n";
                } else {
                    cout << "Value " << value << " not found in the list.\n";
                }
                break;

            case 4:
                cout << "Circular Linked List: ";
                cl.display();
                break;

            case 5:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
