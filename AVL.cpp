#include<iostream>
using namespace std;

class Node{
    public:
    int data, height;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

class Tree{
    public:
    int i, balance;
    Node* ptr;
    
    int height(Node* ptr){
        if(ptr == NULL)
            return 0;
        return ptr->height;
    }

    int maxHeight(int a, int b){
        return (a > b) ? a : b;
    }

    int getBalance(Node* ptr){
        if(ptr == NULL)
            return 0;
        return height(ptr->left) - height(ptr->right);
    }

    Node* rightRotate(Node* y){
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right))+1;
        x->height = max(height(x->left), height(x->right))+1;
        return x;
    }

    Node* leftRotate(Node* x){
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right))+1;
        y->height = max(height(y->left), height(y->right))+1;
        return y;
    }

    Node* insert(Node* ptr, int data){
        Node* newnode = new Node(data);
        if(ptr == NULL)
            return newnode;
        else if(data > ptr->data)
            ptr->right = insert(ptr->right, data);
        else if(data < ptr->data)
            ptr->left = insert(ptr->left, data);
        else
            return ptr;
        ptr->height = 1 + maxHeight(ptr->left->height, ptr->right->height);
        balance = getBalance(ptr);
        if(balance > 1 && data < ptr->left->data)
            return rightRotate(ptr);
        if(balance > 1 && data > ptr->left->data){
            ptr->left = leftRotate(ptr->left);
            return rightRotate(ptr);
        }
        if(balance < -1 && data < ptr->right->data)
            return leftRotate(ptr);
        if(balance < -1 && data > ptr->right->data){
            ptr->right = rightRotate(ptr->right);
            return leftRotate(ptr);
        }
        return ptr;
    }

    void print(Node* ptr, int space = 0){
        if(!ptr)
            return;
        space += 10;
        print(ptr->right, space);
        cout<<endl;
        for(i=10; i<space; i++)
            cout<<" ";
        cout<<ptr->data<<endl;
        print(ptr->left, space);
    }
};

int main(){
    Node* root = NULL;
    Tree t;
    root = t.insert(root, 15);
    t.insert(root, 20);
    t.insert(root, 5);
    t.insert(root, 10);
    t.insert(root, 25);
    t.insert(root, 35);
    t.insert(root, 18);
    t.print(root);
    return 0;
}