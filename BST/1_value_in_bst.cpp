// Find a value in a BST Solution
//1_value_in_bst.cpp

#include<iostream>
using namespace std;

struct Node{
    public:
        int data;
        Node* right;
        Node* left;
};

Node* insert_recur(Node* root, int data){
    if(root==NULL){
        Node* temp = new Node;
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    else{
        if(data > root->data)   root->right = insert_recur(root->right, data);
        else root->left = insert_recur(root->left, data);
    }
    return root;
}

bool find_data(Node *root, int data){
         //Base Case
         if(root == NULL) return false;

         if(data > root->data)
                return find_data(root->right, data);
              
       
         else if(data < root->data)
                return find_data(root->left, data);
         
          return true;
}

int main(){
    Node* root = NULL;
    root = insert_recur(root, 40);
    root = insert_recur(root, 50);
    root = insert_recur(root, 10);
    root = insert_recur(root, 70);
    root = insert_recur(root, 30);
    root = insert_recur(root, 60);
    root = insert_recur(root, 20);
    cout<<"Enter data to be found :- ";
    int m;
    cin >> m;
    cout << find_data(root, m);
    return 0;
    }