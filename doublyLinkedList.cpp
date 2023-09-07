#include<iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

node* createDLL(node *head)
{
    node *ptr,*newNode;
    newNode = new node();
    int x;
    cout<<"Enter elements:";
    cin>>x;
    newNode->data=x;
    newNode->prev=nullptr;
    newNode->next=nullptr;
    if(head==nullptr)
    {
        head=newNode;
    }
    else{
        ptr=head;
        while(ptr->next!=nullptr)
        {
            ptr=ptr->next;
        }
        ptr->next=newNode;
        newNode->prev=ptr;
    }
    return head;
};

void printForward(node *head)
{
    node *ptr;
    ptr=head;
    while(ptr!=nullptr)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
void printBackward(node *head)
{
    node *ptr;
    ptr=head;
    while(ptr->next!=nullptr)
    {
        ptr=ptr->next;
    }
    while(ptr!=nullptr)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->prev;
    }
}

int main()
{
    node *head;
    head = new node();
    head=nullptr;
    int n;
    cout<<"Enter number of Elements:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        head=createDLL(head);
    }
    cout<<"LL int forward direction:-"<<endl;
    printForward(head);
    cout<<endl;
    cout<<"LL int backward direction:-"<<endl;
    printBackward(head);
    return 0;
}
