#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node(){
        int val = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }

};

void insertAtHead(Node* &head, int d){

    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        return;
    }else{
        Node* temp = new Node(d);
        head -> prev = temp;
        temp -> next = head;
        head = temp;
    }
}

void insertAtTail(Node* &tail, int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        return;
    }else{
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void inserAtAnyPosition(Node* &head, Node* &tail, int position, int d){

    if(position == 1){
        insertAtHead(head ,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt != position){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return;
    }
    
    Node* nodetoinsert = new Node(d);
    temp -> prev -> next = nodetoinsert;
    nodetoinsert -> prev = temp -> prev ;
    temp -> prev = nodetoinsert;
    nodetoinsert -> next = temp;
}

void deleteNode(Node* head, int position){
    Node* temp = head;
    int cnt = 1;
    while(cnt != position){
        temp = temp -> next;
        cnt++;
    }

    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
   
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

    

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    // insertAtHead(head, 20);
    // insertAtHead(head, 30);
    // insertAtHead(head, 40);
    // insertAtHead(head, 50);
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    inserAtAnyPosition(head, tail, 5, 60);
    deleteNode(head, 3);
    deleteNode(head, 2);
    print(head);

}