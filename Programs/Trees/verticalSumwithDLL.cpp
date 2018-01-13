#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int lefti = 1;
int righti = 2;
struct dll *head;
struct  tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

struct  dll
{
    int data;
    struct dll *previous;
    struct dll *next;
};

 struct dll * insert(struct dll * root,int operation)
{
        struct dll * node = new(struct dll);
        node->data = 0;
        node->previous = NULL;
        node->next = NULL;
    if(root == NULL)
    {
        head = node;
        cout<<"Creating Head Node"<<endl;
        return node;
        
    }
    else
    {
        if(operation == lefti)
        {
          root->previous = node;
          node->next = root;
        }
        
        if(operation == righti){
            root->next == node;
            node->previous = root;
            
        }
        
       return node;    
    }
    
}

void verticalSum(struct tree *t, struct dll *cn , struct dll *prev, int operation)
{
    if(t==NULL)
    return;
    if(cn==NULL)
    {
        //cout<<"  "<<t->data<<" "<<"Cuurent Node::"<<cn<<"previous node::"<<prev<<" Operation::"<<operation<<endl;
        cn = insert(prev,operation);
        //cout<<t->data<<endl;
    }
     cn->data = cn->data*10 + t->data;
    verticalSum(t->left,cn->previous,cn,lefti);
    verticalSum(t->right,cn->next,cn,righti);
    
}





struct tree* newNode(int data) 
{
	struct tree* node = (struct tree*)
								malloc(sizeof(struct tree));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}


int main()
{
	struct tree *root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->left->left =newNode(8);
	root->left->left->right =newNode(9);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	verticalSum(root,NULL,NULL,0);
    cout<< head->data<<endl;
    cout<<head->previous->data;
    

    return 0;
}


