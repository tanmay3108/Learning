#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<list>
using namespace std;
struct nod
{
int data;
struct nod *left;
struct nod *right;
};
int count=0;
void insert(int d,struct nod**root)
{
     struct nod *q=*root;
     if(*root==NULL)
     {
       struct nod *r=(struct nod*)malloc(sizeof(struct nod)); 
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

void display(struct nod *root)
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
 void bfs(struct nod **head)
 {
 	struct nod *r=*head;
  list<struct nod *>link;
  link.push_back(r);
  while(link.size()!=0)
  {
    struct nod *x=link.front();
    link.pop_front();
    if(x==NULL)
      continue;
    link.push_back(x->left);
    link.push_back(x->right);
    cout<<(x->data)<<"->";
}
  
  
 }



int main()
{
      struct nod *root=NULL;
      insert(20,&root);
      insert(15,&root);
      insert(18,&root);
      insert(25,&root);
      insert(30,&root);
      bfs(&root);
      return 0;
 }