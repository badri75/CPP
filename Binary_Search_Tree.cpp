#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree{
    public:
    Node* root = NULL;
    Node* ptr;
    Node* temp;
    int i;

    Node* insert(Node* ptr, int data){
        Node* newnode = new Node(data);
        if(!ptr)
            return newnode;
        else if(ptr->data > data)
            ptr->left = insert(ptr->left, data);
        else
            ptr->right = insert(ptr->right, data);
        return ptr;
    }

    Node* findmin(Node* ptr){
        if(ptr->left != NULL)
            return findmin(ptr);
        else
            return ptr;
    }

    Node* del(Node* ptr, int data){
        if(data > ptr->data)
            ptr->right = del(ptr->right, data);
        else if(data < ptr->data)
            ptr->left = del(ptr->left, data);
        else{
            if(ptr->left == NULL && ptr->right == NULL)
                ptr = NULL;
            else if(ptr->left == NULL || ptr->right == NULL){
                if(ptr->left == NULL)
                    temp = ptr->right;
                else
                    temp = ptr->left;
                free(ptr);
                return temp;
            }
            else{
                temp = findmin(ptr->right);
                ptr->data = temp->data;
                ptr->right = del(ptr->right, temp->data);
            }
        }
    }

    void inorder(Node* ptr){
        if (!ptr)
            return;
        inorder(ptr->left);
        cout<<ptr->data<<"\t";
        inorder(ptr->right);
    }

    void preorder(Node* ptr){
        if (!ptr)
            return;
        cout<<ptr->data<<"\t";
        preorder(ptr->left);
        preorder(ptr->right);
    }

    void postorder(Node* ptr){
        if (!ptr)
            return;
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->data<<"\t";
    }

    //I have no clue on how the below coding works
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
    t.inorder(root);
    t.print(root);
    cout<<"\n\n";
    t.del(root,20);
    t.print(root);
    return 0;
}