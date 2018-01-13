#include<iostream>
#include<cmath>
#include<cstring>
#define x " ABCDEF"
using namespace std;
int convert(char *n,int base,int b,int count)
{

if(b==0)
	return 0;
	b=b-1;
	int d;


		if(n[b]>=65)
		{
			d=n[b]-64;
			d=d+9;
		}
		else
		d=n[b]-'0';
	return ((d*(pow(base,count)))+convert(n,base,b,count+1));

}
void to(int base,int n)
{   
	/*if(i>7)
		return;
*/
	if(n==0)
	{
	  /* int w=7-i;
		while(w--)
		cout<<(" ");*/
		return;
	}
	int num=n;
	int a=n%base;
	to(base,n/base);
	if(a>9)		
		cout<<x[a%9];
	else
		cout<<a;
	
	

}
int main()
{
   char num[100]={0};
   int frombase;
   int tobase;
   int t;
   cin>>t;
   while(t--)
   {
   cin>>num>>frombase>>tobase; 
   int w=convert(num,frombase,strlen(num),0);
   to(tobase,w);
   
   }
}