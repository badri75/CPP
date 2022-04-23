#include<iostream>
#include<conio.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class List{
    Node* head;
    public:
    List(){
        head = NULL;
    }
    void insert(int data){
        Node* newnode = new Node(data);
        if(head == NULL){
            head = newnode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
    }
};

int main(){
    List ll;
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.insert(40);
    ll.print();
    return 0;
}