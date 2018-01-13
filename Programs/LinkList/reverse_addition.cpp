#include<iostream>
#include<cmath>
using namespace std;


int reverse(int n)
{
	int s=0;
	while(n)
	{
       s=s*10+(n%10);
       n=n/10;
	}
	return s;

}


int main()
{
	int t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<endl<<(reverse(reverse(a)+reverse(b)))<<endl;
	

	}


	return 0;

}