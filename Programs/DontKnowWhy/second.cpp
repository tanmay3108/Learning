#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


/* A binary tree node has data, pointer to left child 
and a pointer to right child */
int sum=0;
struct node 
{
	int data;
	struct node* left;
	struct node* right;
};


void maxDepth(struct node* node,int sum) 
{

if (node==NULL) 
	return;
	sum=sum*10+node->data;
if(node->left==NULL && node->right==NULL)
   {
   	cout<<sum<<endl;
   	return;
   }    

	maxDepth(node->left,sum);
	maxDepth(node->right,sum);
    
}
 

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data) 
{
	struct node* node = (struct node*)
								malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

int main()
{
	struct node *root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(4);
	root->right->right = newNode(5);

	maxDepth(root,0);
    cout<<endl<<sum<<endl; 
	getchar();
	return 0;
}
