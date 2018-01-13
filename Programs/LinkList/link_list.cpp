#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

struct node
{
int data;
struct node* next;
};

void insert(int data,struct node** head)
{ 
	struct node *t=new(struct node);
	//struct node *t=(struct node*)malloc(sizeof(struct node)) ;
	struct node *r=*head;
	if(*head==NULL)
	{
       t->data=data;
       t->next=NULL;
       *head=t;
	}
	else
	{
		while(r->next)
		{
			r=r->next;
		}

	   t->data=data;
       t->next=NULL;
       r->next=t;		
	}

		
}

void display(struct node** head)
{
	struct node* r=*head;
	while(r)
	{
		cout<<r->data<<"->";
		r=r->next;
	}
	cout<<endl;

}
void reverse(struct node** head)
{
	struct node *p,*q;
	int t;
	p=*head;
	q=(p->next)->next;
	while(p&&q)
	{
      t=p->data;
      p->data=q->data;
      q->data=t;
            
      p=p->next;
      q=q->next;
      if(p&&q)
      {
       t=p->data;
       p->data=q->data;
       q->data=t;      	
      }
      else
      	break;
      

      p=q->next;
      if(p)
      {
      	if(p->next)
      q=(p->next)->next;
      }
      else
      	q=NULL;

	}
}
int main()
{
  int t;
  cout<<"Enter the number of nodes";
  cin>>t;
  struct node *head=NULL;
  while(t--)
  {
  	int a;
  	cout<<"Enter the value";
  	cin>>a;
  	insert(a,&head);
  }
  display(&head);
  reverse(&head);
  display(&head);

}
