#include<iostream>
using namespace std;

int arr[]={1,2,0,40,0,0,6,4,2,0,0,1};
void shiftZeroToEnd(int arr[],int n)
{
	int c=0; //Increase if arr[i] not equal to zero;
	for(int i =0;i<n;i++)
	{
		if(arr[i]!=0)
		{
		  arr[c]=arr[i];
		  c++;
		}
		
	}
	while(c<n)
	arr[c++]=0;
}
main()
{   int n=12;
	shiftZeroToEnd(arr,n);
	int i=0;
	while(i<n)
	cout<<arr[i++]<<endl;
}