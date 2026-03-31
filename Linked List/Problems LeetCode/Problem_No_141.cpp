// Detect And Remove Cycle In Linked List

#include <iostream>
#include <vector>

using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

void InsertAtHead(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&Tail, int val)
{
    Node *temp = new Node(val);
    Tail->next = temp;
    Tail = temp;
}

void Print(Node *&head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    // insertAtHead(head, 20);
    // insertAtHead(head, 30);
    // insertAtHead(head, 40);
    // insertAtHead(head, 50);
    // InsertAtTail(tail, 20);
    InsertAtTail(tail, 30);
    InsertAtTail(tail, 40);
    InsertAtTail(tail, 50);

    Print(head);
}