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
    public:
    Node* head = NULL;
    int count = 0;

    void insert(int data, int pos = 100){
        Node* newnode = new Node(data);
        Node* ptr = head;
        if(head == NULL || pos == 1){
            newnode->next = head;
            head = newnode;
        }
        else if(pos <= count){
            for(int i=1; i<pos-1; i++){
                ptr = ptr->next;
            }
            Node* temp = ptr->next;
            ptr->next = newnode;
            newnode->next = temp;
        }
        else{
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
        count++;
    }

    void del(int data){
        Node* ptr = head;
        Node* temp;
        if(head->data == data){
            temp = head;
            head = temp->next;
        }
        else{
            while(ptr->next->data != data){
                ptr = ptr->next;
            }
            temp = ptr->next;
            ptr->next = temp->next;
        }
        free(temp);
        count--;
    }

    void print(){
        Node* ptr = head;
        while(ptr != NULL){
            cout<<ptr->data<<"\t";
            ptr = ptr->next;
        }
        cout<<"\n"<<count;
    }
};

int main(){
    List ll;
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.insert(40);
    ll.insert(50,4);
    ll.del(40);
    ll.print();
    return 0;
}