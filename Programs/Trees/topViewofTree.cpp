#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;

};
struct node* getNode(int a)
{ 
   struct node *n = new(struct node);
   n->data=a;
   n->left=NULL;
   n->right=NULL;
   return n;
}
map<int,vector<int>> hm;
vector<int> vec;
void verticalTraverse(struct node *root,int hd)
{
	if(root==NULL)
	return;
	hm[hd].push_back(root->data);
	verticalTraverse(root->left,hd-1);
	verticalTraverse(root->right,hd+1);
}
int main() 
{
    struct node * head = getNode(10);
    struct node * b = getNode(23);
    struct node * c = getNode(26);
    head->left=b;
    head->right=c;
    c->left=getNode(30);
    c->right=getNode(32);
	verticalTraverse(head,0);
	map<int,vector<int>>::iterator it;
	/*
	*For hashmap iterator has to variables first and second where first is key and second is varaible
	*/
	for(it=hm.begin();it!=hm.end();it++)
	{
		cout<<it->second[0]<<endl;
	}
}