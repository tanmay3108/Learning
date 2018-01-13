#include<stdio.h>
#include<math.h>
int ifprime(int n)
{
 	
 	int i=0;
 	for(i=3;i<sqrt(n);i+2)
 	{
	 if(n%i==0)
 	return 0;
}
return 1;
 	}
main()
{
 	  int t,a,b;
 	  scanf("%d",&t);
 	  while(t-->0)
 	  {
 	  scanf("%d%d",&a,&b);
 	  
 	  int x=a;
 	  for(;x<=b;x++)
 	  {             if(x==1) 
 	                continue;
	   				if(x==2)
	   				printf("%d",2);
 	                if(x==3)
                    printf("%d",3); 
	   				
	   				   if(((x+1)%6==0)||((x-1)%6)==0)
	   				   if(ifprime(x))
	   				   printf("%d",x);
	   				   
	   				   }
	  
 	  
	  }
 	  }

