#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>


/*
* this is recursive approach with time complexity n^2 
*  Same as brute force
*  Efficient solution is getKsumSubarray7.cpp
*
*/
using namespace std;

void printElements(int from,vector<int> & path)
{
    for(int m=from;m<path.size();m++)
    {
        cout<<path[m]<<"->";
    }
    cout<<endl;
}

void printSum(int a[],int size,int k, vector<int > & path,int i)
{
	if(i==size)
	return;
	path.push_back(a[i++]);
	printSum(a,size,k,path,i);
	int f=0;
	for(int j=path.size()-1;j>=0;j--)
	{
		f+=path[j];
		if(f==k)
			printElements(j,path);
	}
	path.pop_back();
}


int main()
{
	int a[]={10,-1,7,2,3,4,5,-3};
	int k=9;
	vector<int> path;
	printSum(a,8,k,path,0);
}