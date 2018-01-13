#include<iostream>
using namespace std;
#define ll long long
#define mod 1000000007
 void multiply(ll int F[2][2],ll int M[2][2])
{
  ll int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  ll int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  ll int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  ll int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
  F[0][0] = x%mod;
  F[0][1] = y%mod;
  F[1][0] = z%mod;
  F[1][1] = w%mod;
}
void power(ll int F[2][2],ll int n)
{
	if(n==0||n==1)
		return;
	ll int M[2][2]={{1,1},{1,0}};
	power(F,n/2);
	if(n%2==0)
	{
		multiply(F,F);
	    
	}
	else
	{
	multiply(F,F);
	multiply(F,M);
     }
	
		
}

int fibo(ll int n)
{
	if(n==0)
		return 0;
	if(n==1||n==2)
		return 1;
	if(n==3)
		return 2;



	ll int F[2][2]={{1,1},{1,0}};
	power(F,n-1);
	

	return F[0][0];
}

int main()
{
	
	int t;
	cin>>t;
while(t--)
{
	ll int sum=0;
	ll int m;
	ll int n;
	cin>>n>>m;
	cout<<endl;
	int a=fibo(n);
	int b=fibo(n+1);
	sum=a+b;
	int i=2;
    while(i<=m-n)
    {

      
      int c=a+b;
    	a=b;
    	b=c;
    	sum=sum+c;
      sum=sum%mod;
      i++;
      
    }
    cout<<sum<<endl;
   } 
	return 0;
}