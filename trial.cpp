#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *getnode(int value)
{
    node *temp = new node;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node *insert_bst(node *roots, int value)
{
    if (roots == NULL)
    {
        return getnode(value);
    }
    if (roots->data > value)
    {
        roots->left = insert_bst(roots->left, value);
    }
    else if (roots->data < value)
    {
        roots->right = insert_bst(roots->right, value);
    }
    return roots;
}



//Function to find minimum in a tree. 
node* FindMin(node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}




// Function to search a delete a value from tree.
struct node* Delete(struct node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			struct node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}







int leaf_sum(node *roots)
{
    if (roots == NULL)
    {
        return 0;
    }
    if (roots->left == NULL && roots->right == NULL)
    {
        return roots->data;
    }
    return (leaf_sum(roots->left) + leaf_sum(roots->right));
}
int main()
{
    node *root = new node;
    root = NULL;
    int value;
    do
    {
        cin >> value;
        if (value > 0)
        {
            root = insert_bst(root, value);
        }
    } while (value > 0);
    // Inorder(root);
    cout << "Sum of all leaf nodes are " << leaf_sum(root);
    return 0;
}