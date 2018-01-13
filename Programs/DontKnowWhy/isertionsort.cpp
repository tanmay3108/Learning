/*
*Stable sort
*
*/
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

void insertionSort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int choosen = arr[i+1];
		int choosenPos = i+1;
		for(int j=i;j>=0;j--)
		{
			if(choosen<arr[j])
			{
				arr[choosenPos]=arr[j];
				arr[j]=choosen;
				choosenPos=j;
			}
			else
			{
				break;
			}
		}
	}
}


int main() {
	 
	int arr[]={15, -2, 2, -8, 1, 7, 10, 23};
	int n=8;
	insertionSort(arr,8);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}