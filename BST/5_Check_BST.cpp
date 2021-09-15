// Check if a tree is a BST or not  Solution

//naive method
//O(n)

//Just the utility functions
vector<int> arr; //global declaration

    void inorder(Node* root){
        if(root == NULL) return;
    
        inorder(root->left);
        arr.push_back(root->data);
        inorder(root->right);
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        
        inorder(root);
        
        for(int it = 0; it<arr.size()-1; it++){
            if(arr[it]>=arr[it+1])     return false;
        }
        return true;
    }


//efficient method
//O(n)


  //min = INT_MIN
  //max = INT_MAX
int isBSTUtil(node* node, int min, int max)
{
    /* an empty tree is BST */
    if (node==NULL)
        return 1;
             
    /* false if this node violates
    the min/max constraint */
    if (node->data < min || node->data > max)
        return 0;
    
    //recursively iterate the tree
    return  isBSTUtil(node->left, min, node->data-1) && 
            isBSTUtil(node->right, node->data+1, max); // Allow only distinct values
}