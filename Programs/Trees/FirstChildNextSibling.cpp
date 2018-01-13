#include<cstdlib>
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *fc; //fc->first child
	struct node *ns; //ns->next sibling
};

struct node * createNode(int a)
{
	struct node *n = NULL;
	n = (struct node*)malloc(sizeof(struct node));
	n->data = a;
	n->fc=NULL;
	n->ns=NULL;
	return n;
}

struct node * search(int employee,struct node **oh)
{
    struct node *ceo = *oh;
    struct node *l;
    struct node *r;   
	if(ceo==NULL)
	return NULL;
	if(ceo->data==employee)
	return ceo;
	else
	{
	  l=search(employee,&(ceo->fc));
	  r=search(employee,&(ceo->ns));
	}

    if(l!=NULL)
    return l;
    else return r;
}

void insertEmployee(struct node **oh,int a,int m)
{

    struct node *ceo = *oh; 
    struct node *newEmployee = createNode(a);
	if(m==-1)
	{
		      
		newEmployee->fc=ceo;
		*oh=newEmployee;
		return;
	}
	else
	{
		struct node *manager = search(m,oh);
		if(manager->fc==NULL)
		manager->fc=newEmployee;
		else
		{
		   struct node *firstChild =manager->fc;
		   while(firstChild->ns)
		   {
		      firstChild=firstChild->ns;
		   }
		   firstChild->ns=newEmployee;
		   return;
		}
	}
}

struct node* lca(struct node **oh,int a,int b)
{   
	
	struct node *ceo=*oh;
	if(ceo==NULL)
	{
		return NULL;
	}
	if(ceo->data==a||ceo->data==b)
	{
		return ceo;
	}

	struct node *firstChild = (ceo->fc);
	struct node *secondChild = ceo->fc==NULL:NULL? (ceo->fc)->ns;
	struct node *yyy=NULL;
    while(secondChild)
    {

    	struct node *xxx = lcs(&secondChild,a,b);
    	if(xxx!=NULL)
    	{
    		
    		yyy=xxx;
    		break;
    	}
    	secondChild=secondChild->ns;	
    }
        	   	
     if(firstChild&&secondChild)
     	return ceo;
     else (secondChild!=null):
		
	
	
}
int main()
{
  struct node *ceo =NULL;
  int a=100;
  //cout<<a<<endl;
  insertEmployee(&ceo,a,-1);
  insertEmployee(&ceo,99,a);
  insertEmployee(&ceo,98,a);
  insertEmployee(&ceo,97,a);
  insertEmployee(&ceo,96,97);
  insertEmployee(&ceo,95,97);
  //cout<<ceo->data<<endl;
  //cout<<(ceo->fc)->data<<endl;
  //cout<<((ceo->fc)->ns)->data<<endl;
  //cout<<(search(92,&ceo))->data<<endl;
  
  cout<<lca(&ceo,96,98)->data;
}