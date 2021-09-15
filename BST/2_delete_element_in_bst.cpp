// Deletion of a node in a BST Solution
//delete_element_in_bst.cpp

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* right;
        Node* left;
};

Node*  insert_element(Node* root, int data){
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

void print_element(Node* root){
    
    if(root == NULL) return;
    print_element(root->left);
    cout << root->data << " ";
    print_element(root->right);
}


Node* delete_element_iter(Node* root, int data){
    Node* curr = root;
    Node* prev = NULL;

    //traversing to the key to be deleted
    while (curr != NULL && curr->data != data) {
        prev = curr;
        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    
    //key not found 
    if (curr == NULL) {
        cout << "Data = " << data << " not found in the"
             << " provided BST.\n";
        return root;
    }

    //atmost one node
    if (curr->left == NULL || curr->right == NULL) {
        Node* newCurr;

        if (curr->left == NULL)
            newCurr = curr->right;
        else
            newCurr = curr->left;
        
        if(prev == NULL) return newCurr;

        if(curr == prev->right)   prev->right = newCurr;
        else    prev->left = newCurr;  
        free(curr);
    }

    //two children
    else{
            Node* p = NULL;
            Node* temp;

            temp = curr->right;
            while (temp->left != NULL) {
                 p = temp;
                temp = temp->left;
            }

            if (p != NULL)
                p->left = temp->right;
            else 
                curr->right = temp->right;

        curr->data = temp->data;
        free(temp);
     }
        return root;
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
    print_element(root);
    cout <<"\n";
    cout<<"Enter data to be deleted :- ";
    int m;
    cin >> m;
    root = delete_element_iter(root, m);
    print_element(root);
    cout <<"\n";


    return 0;
}