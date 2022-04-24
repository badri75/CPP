#include<iostream>
#include<conio.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class List{
    public:
    int count = 0;
    Node* head = NULL;
    Node* ptr;
    Node* temp;

    void insert(int data, int pos = 100){
        Node* newnode = new Node(data);
        if(head == NULL || pos == 1){
            newnode->next = head;
            newnode->prev = NULL;
            head = newnode;
        }
        else if(pos <= count){
            ptr = head;
            for(int i=1; i < pos-1; i++)
                ptr = ptr->next;
            newnode->prev = ptr;
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
        else{
            ptr = head;
            while(ptr->next != NULL)
                ptr = ptr->next;
            newnode->prev = ptr;
            newnode->next = NULL;
            ptr->next->prev = newnode;
            ptr->next = newnode;
        }
        count++;
    }

    void del(int data){
        ptr = head;
        if(head->data == data){
            temp = head;
            head = head->next;
        }
        else{
            while(ptr->next->data != data){
                ptr = ptr->next;
            }
            temp = ptr->next;
            ptr->next = temp->next;
            if(temp->next != NULL)
                temp->next->prev = ptr;
        }
        free(temp);
        count--;
    }
    
    void display(){
        ptr = head;
        while(ptr != NULL){
            cout<<ptr->data<<"\t";
            ptr = ptr->next;
        }
    }
};

int main(){
    List ll;
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.insert(40);
    ll.insert(50, 4);
    ll.del(40);
    ll.display();
    return 0;
}