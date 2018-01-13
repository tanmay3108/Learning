#include<iostream>
#include<cstring>
#include<cmath>
#include"linklist.h"
using namespace std;
struct node * reverse(struct node *head)
{
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
		return head;
	struct node *second=head->next;
	head->next=NULL;
	struct node *r=reverse(second);
	second->next=head;
	return r;
}
int main()
{
	struct node *head=createll();
	insert(1,&head);
	insert(2,&head);
	insert(3,&head);
	insert(4,&head);
	display(&head);
    struct node *r=reverse(head);
    display(&r);
	return 0;
}
