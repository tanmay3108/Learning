#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#include<math.h>
int i=0;
int path[100]={0};
int pathT0[100]={0};
int j=0;
struct node
{
int data;
struct node *left;
struct node *right;
};
int count=0;
insert(int d,struct node**root)
{
     struct node *q=*root;
     if(*root==NULL)
     {
       struct node *r=(struct node*)malloc(sizeof(struct node)); 
        r->data=d;
        r->left=NULL;
        r->right=NULL;
        *root=r;
     }
        
     else
     {
         if(q->data>d)
         insert(d,&(q->left));              
         if(q->data<d)
         insert(d,&(q->right));              
                                                  
     }
                          
}

display(struct node *root)
{
            
  if(root==NULL)
  return;          
  else 
  {
    printf("%d\n",(root->data));             
    display(root->left);           
    display(root->right); 
  }
        
}
        
        
        
           kth_largest(int k,struct node *root)
           {
                           if(root==NULL)
                           return;                      
                           kth_largest(k,root->right);
                           count++;
                           if(count==k)
                           printf("Kth largest element %d\n",root->data);
                           kth_largest(k,root->left);
                                            
                           
           }
        
        
struct node * findMin(struct node *root)  //just move left untill NULL is found
{
struct node *r=root;
 if(r==NULL)
 return NULL;
 else 
 {
  if(r->left==NULL)
  return r;
  else
  return findMin(r->left);
 } 

}

struct node * findMax(struct node *root)//just move right untill NULL is found
{
struct node *r=root;
 if(r==NULL)
 return NULL;
 else 
 {
  if(r->right==NULL)
  return r;
  else
  return findMax((r->right));
 } 

}


struct node * search(struct node *root,int number)
{ 

  if(root==NULL)
   return NULL;//If element is not found then returns null
  if(number>root->data)
    return(search(root->right,number));
  else if(number<root->data)
     return(search(root->left,number));  
  else if(number==root->data)
     return root; //if found returns  
}
 void display_path(int arr[],int i,int d)//print_path
 {    
 	  printf("Path from root to %d\n",d);
 	  int j;
  	  for(j=0;j<i;j++)
  	  {
	   				  printf("%d->",arr[j]);
	   				  }
	   				  printf("\n\n");
  }

void print_path(struct node *root,int i,int path[])//prints the path form the root to every  leaf node
{
 	 if(root==NULL)
 	 return;
 	 path[i++]=root->data;
 	 if((root->left==NULL)&&(root->right==NULL))
 	 display_path(path,i,root->data);
 	 else
 	 {
	  	 print_path(root->left,i,path);
	  	 print_path(root->right,i,path);
	 }
 }
 


int height(struct node *root)
{
struct node *r=root;
int l=0,ri=0;
if(r==NULL)
return -1;
else 
{
l=height(r->left);
ri=height(r->right);
if(l>ri)
return 1+l;
else
return 1+ri;
}
}



struct node *delete(struct node *root,int number)
{
 struct node *temp;
 if(root==NULL)
  printf("Not found");
 else if(number<root->data)
  root->left=delete(root->left,number);
 else if(number>root->data)
  root->right=delete(root->right,number);
 else
 { 
    if((root->left)&&(root->right))
    {  
      temp=findMax(root->left); 
      root->data=temp->data;
      root->left=delete(root->left,root->data);
    }
   else
   { //For deleting root with no or onew child

     temp=root;
     if((root->right==NULL)&&(root->left==NULL))
        root=NULL;

     else if(root->left==NULL)
        root=root->right;
     else if(root->right==NULL)
        root=root->left;
     free(temp);  
   }
 }
return root;
}		

void printPath(int j)
{
   for (int i = 0; i<j;i++)
   {
     printf("%d->",pathT0[j]);
   }
}
void pathFrom(struct node *root,int a,int j)
{
  
  if(root==NULL)
  return;
 pathT0[j++]=root->data;
  if(root->data==a)
  printPath(j);
  else
  {
    printFrom(root->left,a,j);
    printFrom(root->right,a,j);
  }
}

main()
{
      struct node *root=NULL;
      //srand(time(NULL));
      insert(20,&root);
      insert(21,&root);
      insert(22,&root);
      insert(23,&root);
      insert(10,&root);
      insert(18,&root);
      insert(16,&root);
      insert(24,&root);
      
      
      printf("\nHeight=%d\n",height(root));
      display(root);
      
	  print_path(root,i,path);
    pathFrom(root,22,j);      
       //root=delete(root,10);
	  //printf("\n\n%d",(findMin(root))->data);
      //printf("\n\n%d",(findMax(root))->data);
      
      

      
}
        