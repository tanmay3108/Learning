#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define MAX 400
#include<iostream>
using namespace std;
struct ap
{
       char stack[MAX];
       char target[MAX];
       char *t,*s;
       int top;
};


               
      int priority(char y)
       {
           if(y=='^')
           return 3;
           if((y=='/')||(y=='*')||(y=='%'))
           return 2;
           if((y=='+')||(y=='-'))
           return 1;
           else
           return 0;
       }      
               
               
      void push(struct ap *s,char y)
       {
               if(s->top==MAX)
               printf("stack overflow");
               s->top++;
               s->stack[s->top]=y;
                
        }
          
        char pop(struct ap *s)
        {
                 if(s->top==-1)
                 printf("ubderflow");
                 else
                 return s->stack[s->top--];
        }
               
               
      void convert(struct ap *p) 
       {
        
           int f=0;
           char opr;
           while(*(p->s))
            {
              if(isdigit(*(p->s))||isalpha(*(p->s)))
                    {
                      *(p->t)=*(p->s);
                        p->t++;
                        p->s++;                  
                    }
             
              if(*(p->s)=='(')
                    {
                      push(p,*(p->s));
                      p->s++;
                    }
                             
                            if(*(p->s)==')')
                            {             opr=pop(p); 
                                       while(opr!='(')
                                       { *(p->t)=opr;
                                       p->t++;
                                         opr=pop(p);
                                         }
                             
                                            p->s++;
                                            }
                     
                    if((*(p->s)=='/')||(*(p->s)=='*')||(*(p->s)=='+')||(*(p->s)=='-')||(*(p->s)=='%')||(*(p->s)=='^'))       
                    {
                      if(p->top==-1)
                      {
                                    push(p,*(p->s));
                                   
                                    }                                                                                                
                                         else
                                         {
                                             opr=pop(p);
                                             f=0;
                                             while(priority(opr)>=priority(*(p->s)))
                                             {
                                             *(p->t)=opr;
                                             p->t++;
                                             if(p->top==-1)
                                             
                                            {f=1;
                                                            break;
                                            }
                                             opr=pop(p);
                                             }
                                             if(f==0)
                                             push(p,opr);
                                             push(p,*(p->s));
                                         }                                                                                    
                                   
                                    p->s++;
                                                                                                                              }//1if ends
                             
                             
             
       }      //while
        
       while(p->top!=-1)
       
      {
                         *(p->t)=pop(p);
                         p->t++;
      }
       }// function ends here
        
        
       
               
               
               
                void ini(struct ap *p)
              {
                   p->top=-1;
                   } 
              
                
             
               int main()

               {

                clock_t startClock,finishClock;
                double timeCount;
                startClock = clock();
//-----your sort function goes here here--------
 
                     
                     cout<<"Eneter the no. of test cases";
                     int x;
                     cin>>x;
                     while(x--)
                     {
                      struct ap a;
                      struct ap *b;
                      b=&a;
                      a.t=a.target;      
                      cout<<"Enter the Infix equation";
                      char s[400];
                      cin>>s;
                      ini(b);
                      a.s=s;
                      convert(b);
                      *(a.t)='\0';
                      printf("%s\n",a.target);
                  
                      finishClock = clock();
                      timeCount = finishClock - startClock ;
                      printf("%lf",timeCount/100);


                     }  
                     
                      return 0;                                   

                      
                }                                                                