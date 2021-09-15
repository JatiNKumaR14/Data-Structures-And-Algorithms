// Find min and max value in a BST Solution
//min_and_max_in_bst.cpp
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
};

Node* insert_element(Node* root, int data){
    if(root == NULL){
        Node* temp = new Node();
        temp->data = data;
        temp->right = temp->left = NULL;
        return temp;
    }
    else {
        if(data < root->data)   root->left = insert_element(root->left, data);
        else                    root->right = insert_element(root->right, data);
    }
    return root;
}

int max_elememt_in_bst_recur(Node* root){
    if(root->right  == NULL)    return root->data;

     return max_elememt_in_bst_recur(root->right); 
}

int min_elememt_in_bst_iter(Node* root){
    if(root == NULL)    return -1;
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

int main(){
    Node* root = NULL;
    root = insert_element(root, 40);
    root = insert_element(root, 20);
    root = insert_element(root, 10);
    root = insert_element(root, 60);
    root = insert_element(root, 30);
    root = insert_element(root, 50);
    root = insert_element(root, 70);
    root = insert_element(root, 80);
    root = insert_element(root, 75);
    root = insert_element(root, 65);
    cout << "Maximum element in the given bst :- "<< max_elememt_in_bst_recur(root)<<"\n";
    cout << "Minimum element in the given bst :- "<< min_elememt_in_bst_iter(root)<<"\n";

    return 0;
}