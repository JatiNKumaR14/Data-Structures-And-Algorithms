// Find inorder successor and inorder predecessor in a BST Solution
//In_succ_pred.cpp

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* right;
        Node* left;
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

int Inorder_predecessor(Node* root){
    if(root == NULL) return -1;
    Node* temp;
    if(root->left != NULL){
        temp = root->left;
        while(temp->right != NULL)  temp = temp->right;
        return temp->data;
    }
    return root->data;
}

int Inorder_successor(Node* root){
    if(root == NULL) return -1;
    Node* temp = root;
    if(root->right != NULL){
        temp = root->right;
        while(temp->left != NULL)  temp = temp->left;
        return temp->data;
    }

    return root->data;
}


int main(){
    Node* root = NULL;
    root = insert_element(root, 40);   //                            40(root)
    root = insert_element(root, 20);   //                    20                      60
    root = insert_element(root, 10);   //              10         30             50          70     
    root = insert_element(root, 60);   //           7      11                            65        80    
    root = insert_element(root, 30);   //                                                       75
    root = insert_element(root, 50);   // 
    root = insert_element(root, 70);   //    
    root = insert_element(root, 80);   //              (inorder successor of root)   = 30     
    root = insert_element(root, 75);   //              (inorder predecessor of root) =  50   
    root = insert_element(root, 65);      
    root = insert_element(root, 7);      
    root = insert_element(root, 11);      
    cout << "Inorder predecessor :- " << Inorder_predecessor(root) << "\n";
    cout << "Inorder successor :- " << Inorder_successor(root) << "\n";

    return 0;
}