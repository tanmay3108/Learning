#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
//a^(n-1)==1 then not a prime number
using namespace std;
int main()
{
	cout<<"enter the number"<<endl;
	int n=7;
	int f=0;
	cin>>n;
	double z;
	for(int i=0;i<2;i++)
	{
		
		int a=(random()%(n-1))+1;
		cout<<"Random number"<<a<<endl;
		z=pow(a,b);
		cout<<z<<endl;
		z=z%n;
		cout<<"Power raised"<<z;
		if(z!=1)
		{

			f=-1;
			break;
	    }

	}
	if(f==0)
		cout<<n<<"is a prime number"<<endl;
	else
		cout<<"Not a prime number"<<endl;
return 0;
}

