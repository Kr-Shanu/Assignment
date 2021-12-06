#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *getnode(int value)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct node *insert_bst(struct node *roots, int value)
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
struct node* FindMin(struct node* root)
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
			free(root);
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct node *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL) {
			struct node *temp = root;
			root = root->left;
			free(temp);
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


//Function to visit nodes in Inorder
void Inorder(struct node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}




int leaf_sum(struct node *roots)
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
    struct node *root = (struct node*)malloc(sizeof(struct node));
    root = NULL;
    int value;
    printf(" Enter a value and press enter and to stop the program enter a value smaller than 0\n");
    do
    {
        scanf("%d",&value);
        if (value > 0)
        {
            root = insert_bst(root, value);
        }
    } while (value > 0);
    // Inorder(root);
    printf("Sum of all leaf nodes are %d \n", leaf_sum(root));

   printf("Please enter the element to be deleted: ");
   int del;
   scanf("%d",&del);

    Delete(root, del);
    Inorder(root);
    
	
    return 0;
}