#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int a=2;
	if(a==2)
	{
		a=~a+2<<1;
		cout<<a;
	}
	
	
	return 0;
}