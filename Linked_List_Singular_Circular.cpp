#include<iostream>
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
    Node* ptr;
    int count = 0, i;

    void insert(int data, int pos = 100){
        Node* newnode = new Node(data);
        ptr = head;
        if(head == NULL){
            head = newnode;
            newnode->next = head;
        }
        else if(pos == 1){
            newnode->next = head;
            head = newnode;
            for(i=1; i<count; i++)
                ptr = ptr->next;
            ptr->next = head;
        }
        else{
            int a = (pos<=count)?pos-1:count;
            for(i=1; i<a; i++)
                ptr = ptr->next;
            newnode->next = ptr->next;
            ptr->next = newnode;
//            cout<<"\na = "<<a<<endl;
        }
        count++;
    }

    void del(int data){
        ptr = head;
        Node* temp = NULL;
        if(head->data == data){
            temp = head;
            for(i=1; i<count; i++)
                ptr = ptr->next;
            head = head->next;
            ptr->next = head;
        }
        else{
            while(ptr->next->data != data)
                ptr = ptr->next;
            temp = ptr->next;
            ptr->next = temp->next;
        }
        free(temp);
        count--;
    }
    
    void print(){
        ptr = head;
        for(i=0; i<count; i++){
            cout<<ptr->data<<"\t";
            ptr = ptr->next;
        }
//        cout<<"\n"<<count<<endl;
    }
};

int main(){
    List ll;
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.insert(40);
    ll.del(40);
    ll.insert(50,2);
    ll.print();
    return 0;
}