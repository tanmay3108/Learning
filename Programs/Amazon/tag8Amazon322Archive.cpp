/*
*Return a maximum length sequence containing consecutive numbers from a *binary tree. i.e.
            90
           /  \
          1   66
         /      \            
        2       67
      /   \    /
     5     4  68
          /    \
        99      100
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct node 
{
	int data;
	struct node* left;
	struct node* right;
};


struct node* newNode(int data) 
{
	struct node* node = (struct node*)
								malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}


int maximum;
void largestSeq(struct node *root, int l)
{
    if(root==NULL)
    return;
    if(l>maximum)
    {
        maximum = l;
    }
    if(root->left != NULL)
{
    if((root->left)->data-1 == root->data)
    largestSeq(root->left,l+1);
    else
    largestSeq(root->left,0);
}
    
    
    if(root->right != NULL)
{
    if((root->right)->data-1 == root->data)
    largestSeq(root->right,l+1);
    else
     largestSeq(root->right,0);
}
}
int main()
{
	struct node *root = newNode(1);

    root->left = newNode(2);
    root->left->right  = newNode(3);
    root->left->right->right  = newNode(4);
    root->left->right->left  = newNode(4);
    root->left->right->left->left  = newNode(5);
    root->left->right->left->left->right  = newNode(6);
    root->right = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->right->right->right = newNode(9);
	largestSeq(root,0);
	std::cout << maximum << std::endl;

    return 0;
}
