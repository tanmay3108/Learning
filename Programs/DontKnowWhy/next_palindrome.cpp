#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int flag=0;

void palindrome(string s,int l,int u)
{
	if(l>=u)
	{
		flag=1;
		return;
	}
	if(s[l]==s[u])
		 palindrome(s,l+1,u-1);
	else
	{ 
		flag=-1;
		return;
	}
}
int nextpalin(int n)
{
	
		//for case where number is 99999.....
	float  no_digits=log(n)/log(10);
	no_digits++;
    long long a=pow(10,(int)no_digits);
    if(int(a-n)==1)
	return n+2;
    //for case when input itself is a palindrome
     palindrome(n);
     if(flag==1)
     {
     	if(no_digits%2==0)
     	{
     		
     	}

     }


}

int main()
{

	int n;
	//cin>>n;
	n=999;
	int x=nextpalin(n);
	cout<<x;
	return 0;
}