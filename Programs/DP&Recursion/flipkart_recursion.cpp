#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;

//char arr[4][5]={{"NNYN"},{"NNYN"},{"NNNN"},{"NYYN"}};
char arr[4][5]={{"NNNN"},{"NNNY"},{"NYNY"},{"YNNN"}};
int NY(int i)
{
	int sum=0;
	for(int j=0;j<4;j++)
	{
		if(arr[i][j]=='Y')
			sum++;
		else
			continue;
	}
	return sum;
}

int income(int i)
{
	int sum=0;
	if(NY(i)==0)
		return 1;
	else
	{
		for(int j=0;j<4;j++)
		{   if(i==j)
		        continue; 
			if(arr[i][j]=='Y')
				sum=sum+income(j);
			else
				continue;
		}
		return sum;
	}
		
}
int main()
{

	cout<<income(0)<<endl;
	cout<<income(1)<<endl;
	cout<<income(2)<<endl;
	cout<<income(3)<<endl;
}