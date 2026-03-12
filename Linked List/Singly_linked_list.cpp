#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this -> data = val;
        this -> next = NULL;
    }

};

void insertAtHead(Node* &head, int val){
    if(head == NULL){
        Node* temp = new Node(val);
        head = temp;
        return;
    }
    else{
         Node* n = new Node(val);
         n -> next = head;
         head = n;
    }
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}


Node* middle(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast -> next!=NULL && fast != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

    }
    return slow;
}



int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50); 
    cout<<middle(head) -> data<<endl;  
    insertAtTail(tail, 0);
    insertAtTail(tail, -10);
    insertAtTail(tail, -20);
    insertAtTail(tail, -30);
    insertAtTail(tail, -40);
    insertAtTail(tail, -50);
    cout<<middle(head) -> data<<endl;
    print(head);
    cout<<endl;

    return 0;
}