#include <iostream>
#include <cstring>
using namespace std;

int find(int l,int h, int a[],int n)
{
	
	while(l<=h)
	{
		int m =(l+h)/2;
		if((m+1)==n && a[m]==a[m+1])
		{
			h=m-1;
		}
		else if( ((m+1)<n) && a[m]==a[m+1] )
		{
			if(((h-m+2+1)%2)!=0)
			l=m+2;
			else
			h=m-1;
		}
		else if((m-1)==0 && a[m]==a[m-1])
		{
			l=m+1;
		}
		else if((m-1)>0 && a[m]==a[m-1])
		{
			if(((m-2)-l+1)%2!=0)
			h=m-2;
			else
			l=m+1;
		}
		else 
		return a[m];
		
			
	}
}
int main() {
	// your code goes here
	//int a[]={1,1,2,2,3,3,4,5,5};
	//int n = 8;
	//int a[]={1,1,2};
	//int a[]={1,2,2};
	int a[]={1};
	int n = 0;
	cout<<find(0,n,a,n);
	return 0;
}