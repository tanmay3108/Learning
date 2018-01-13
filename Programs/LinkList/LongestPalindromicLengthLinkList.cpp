/*
Length of longest palindrome in linked list

Input  : List = 2->3->7->3->2->12->24
Output : 5
The longest palindrome list is 2->3->7->3->2

Input  : List = 12->4->4->3->14
Output : 2
The longest palindrome list is 4->4
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node* getNode(int d)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;
}
int countMatching(struct node *x,struct node *y)
{
    int c=0;
    struct node *a =x;
    struct node *b =y;
    while(a&&b)
    {
        if(a->data !=b->data)
        break;
        else
        c=c+2;
        a=a->next;
        b=b->next;
    }
    return c;
}
int getPalindromicLength(struct node *head)
{
    int result = 1;
    struct node *prev =NULL;
    struct node *mid = NULL;
    struct node *Next = head;
    struct node *temp;
    while(Next != NULL)
    {
        if(mid == NULL)
        {
            temp = Next->next;
            Next->next = prev;
            prev = Next;
            Next = temp;
            
        }
        else
        {
            mid->next = prev;
            prev = mid;
            mid = NULL;
        }
        
        result = max(result,countMatching(prev,Next));
        
        if(Next !=NULL)
        {
            mid = Next;
        Next = Next->next;
        //cout<<"Entered"<<prev->data<<Next->data;
        result = max(result,countMatching(prev,Next)+1);    
        }
        
    }

    return result;
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

int main() {
    struct node *head = NULL;
    head = getNode(2);
    head->next = getNode(3);
    head->next->next =getNode(7);
    head->next->next->next =getNode(3);
    head->next->next->next->next =getNode(2);
    head->next->next->next->next->next =getNode(9);
    
    struct node *head1 = NULL;
    head1 = getNode(4);
    head1->next = getNode(5);
    head1->next->next =getNode(4);
    display(&head);
    //display(&head1);
    //cout<<countMatching(head,head1);
    cout<<getPalindromicLength(head);
    cout<<endl;
	return 0;
}
