//to create call createll() with return type struct node *
//to insert call insert(data &head)
// to display(&head);
using namespace std;
struct node
{
int data;
struct node* next;
};

struct node * createll()
{
  struct node *head=NULL;
  return head;
}
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



