#include<iostream>
using namespace std;

int caltan(int n)
{   int sum=0;
	if(n==0)
		return 1;
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	for(int i=0;i<=n-1;i++)
	sum=sum+caltan(i)*caltan(n-1-i);
	return sum;		
	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cout<<"Eneter the number";
		cin>>n;
		cout<<endl<<caltan(n)<<endl;;
    }
}