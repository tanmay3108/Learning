#include<iostream>
#include<cstdlib>
#include<cmath>
#include"linklist.h"

using namespace std;

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
  struct node *head=createll();
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
