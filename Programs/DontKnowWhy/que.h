/*
Prototype for using the finction
main()
{
 	  struct Que *q=CreateQue();
 	  Enque(q,5);
 	  Enque(q,6);
 	  Enque(q,7);
 	  Enque(q,8);
 	  printf("%d\n",Deque(q));
 	  printf("%d\n",Deque(q));
 	  printf("%d\n",Deque(q));
 	  printf("%d\n",Deque(q));
 	  printf("%d\n",Deque(q));
 	  getch();
 	  }
*/


struct node
{
 	   int data;
 	   struct node *next;
 	   };
 	   
struct Que
{
 	   struct node *rear;//Enque
 	   struct node *front;//Deque
 	   };
 	   
struct Que *CreateQue()
{
 	   struct Que *q=(struct Que *)malloc(sizeof(struct Que));
 	   q->rear=NULL;
 	   q->front=NULL;
 	   return q;
 	   } 
void Enque(struct Que *q,int d)
{
 			 if(q->rear==NULL)//Empty
 			 {
                struct node *n=(struct node *)malloc(sizeof(struct node));
                n->data=d;
                n->next=NULL;
                q->rear=n;
                q->front=n;
				 
			  						 }
			 else
			 {   struct node *n=(struct node *)malloc(sizeof(struct node));
			     n->data=d;
				 n->next=NULL; 
			  	 q->rear->next=n;
			  	 q->rear=n;
			  	 
			 } 						 
			  						 
}

int Deque(struct Que *q)
{   if(q->front==NULL)
   {
    printf("UNDERFLOW");
	return -1;  
    }
 	struct node *n=q->front;
 	q->front=q->front->next;
 	int data=n->data;
 	free(n);
 	return data;
}			   
