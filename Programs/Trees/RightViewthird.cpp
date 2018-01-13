#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#include<vector>
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
int sum=0;
std::vector<int> v;
int maximum=-1;
struct node 
{
	int data;
	struct node* left;
	struct node* right;
};

void display(vector<int>arr)
{
	vector<int>::iterator it=arr.begin();
	while(it!=arr.end())
	{
		cout<<*it;
		it++;
	}
}
void rightView(struct node* node,int h) 
{

if (node==NULL) 
	return;
h++;	
if(h>maximum)
   {
   	 maximum=h;
   	 cout<<node->data;
   }    

	rightView(node->right,h);
	rightView(node->left,h);
    
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
	root->left->left->left =newNode(8);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	rightView(root,-1);
    display(v);

    return 0;
}
