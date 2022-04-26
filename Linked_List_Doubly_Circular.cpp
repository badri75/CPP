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
        ptr = head;
        if(head == NULL){
            head = newnode;
            newnode->next = head;
            newnode->prev = head;
        }
        else if(pos == 1){
            newnode->next = head;
            newnode->prev = head->prev;
            head = newnode;
            for(i=1; i<count; i++)
                ptr = ptr->next;
//            cout<<ptr->data<<i<<count<<endl;
            ptr->next = head;
            head->prev = ptr;
        }
        else{
            int a = (pos<=count)?pos-1:count;
            for(i=1; i<a; i++)
                ptr = ptr->next;
            newnode->next = ptr->next;
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
            for(i=1; i<count; i++)
                ptr = ptr->next;
            ptr->next = head;
            head->prev = ptr;
        }
        else{
            while(ptr->next->data != data)
                ptr = ptr->next;
            temp = ptr->next;
            ptr->next = temp->next;
            temp->next->prev = ptr;
            // cout<<ptr->data<<"\t"<<temp->data<<endl;
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
    ll.insert(50);
    ll.insert(70, 1);
    ll.del(30);
    ll.print();
    return 0;
}