#include<iostream>
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
    int count = 0, i;
    Node* head = NULL;
    Node* ptr;
    Node* temp;

    void insert(int data, int pos = 100){
        Node* newnode = new Node(data);
        if(head == NULL){
            head = newnode;
            newnode->next = head;
            newnode->prev = head;
        }
        else if(pos == 1){
            newnode->next = head;
            newnode->prev = head->prev;
            head = newnode;
            ptr = head;
            for(i=1; i<=count; i++)
                ptr = ptr->next;
//            cout<<ptr->data<<i<<count<<endl;
            ptr->next = head;
        }
        else if(pos <= count){
            ptr = head;
            for(i=1; i<pos-1; i++)
                ptr = ptr->next;
            newnode->next = ptr->next;
            newnode->prev = ptr;
            ptr->next = newnode;
//            cout<<ptr->data<<endl;
        }
        else{
            ptr = head;
            for(i=1; i<count; i++)
                ptr = ptr->next;
            newnode->next = head;
            newnode->prev = ptr;
            ptr->next->prev = newnode;
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
            for(i=0; i<count; i++)
                ptr = ptr->next;
            head->prev = ptr;
            ptr->next = head;
        }
        else{
            while(ptr->next->data != data)
                ptr = ptr->next;
            temp = ptr->next;
            ptr->next = temp->next;
            temp->next->prev = ptr;
        }
        free(temp);
        count--;
    }

    void print(){
        Node* ptr = head;
        for(i=0; i<count; i++){
            cout<<ptr->data<<"\t";
            ptr = ptr->next;
        }
//        cout<<"\n"<<count;
    }
};

int main(){
    List ll;
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.insert(40);
    ll.insert(70, 3);
    ll.del(10);
    ll.print();
    return 0;
}