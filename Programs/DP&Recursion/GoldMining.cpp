/*
Gold Mine Problem
Given a gold mine of n*m dimensions. 
Each field in this mine contains a positive integer 
which is the amount of gold in tons. 
Initially the miner is at first column but can be at any row. 
He can move only (right->,right up /,right down\) that is from a given cell, 
the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Find out maximum amount of gold he can collect.

Examples:

Input : mat[][] = {{1, 3, 3},
                   {2, 1, 4},
                  {0, 6, 4}};
Output : 12 
{(1,0)->(2,1)->(2,2)}

Input: mat[][] = { {1, 3, 1, 5},
                   {2, 2, 4, 1},
                   {5, 0, 2, 3},
                   {0, 6, 1, 2}};
Output : 16
(2,0) -> (1,1) -> (1,2) -> (0,3) OR
(2,0) -> (3,1) -> (2,2) -> (2,3)

Input : mat[][] = {{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};
Output : 83
*/




#include<iostream>
#include<cstdio>
using namespace std;

int arr[4][4] ={{1,3,1,5},{2,2,4,1},{5,0,2,3},{0,6,1,2}};
int row =4;
int col =4;

bool isValid(int i,int j)
{
	if(i<0 || i>=row)
		return false;
	if(j<0 || j>=col)
		return false;
	return true;
} 

int maxScore(int i, int j)
{
	if(!isValid(i,j))
	{
		return 0;
	}
  if(j == col-1)
  	return arr[i][j];

  return max(max(arr[i][j]+maxScore(i,j+1),arr[i][j]+maxScore(i-1,j+1))
  	,arr[i][j]+maxScore(i+1,j+1));
}

int dp[4][4];
void dynamicPrograming()
{
	for(int j =1;j<col;j++)
	{
		for(int i = 0;i<row;i++)		
		{
			int a = 0;
			int b= 0;
			int c = 0;
			if(isValid(i,j-1))
			{
				a = arr[i][j]+arr[i][j-1];	
			}
			if(isValid(i-1,j-1))
			{
				b = arr[i][j]+arr[i-1][j-1];
			}
			if(isValid(i+1,j-1))
			{
				c = arr[i][j]+arr[i+1][j-1];	
			}
            
            arr[i][j] = max(c,max(a,b));
            
		}
	}
}


int main()
{
     //Recuisive Approach
	//cout<< max(max(maxScore(0,0),maxScore(1,0)),maxScore(2,0));
	dynamicPrograming();
	for(int i =0 ;i<row;i++)
{
	for(int j = 0 ;j<col;j++)
	{
		cout<<arr[i][j]+" ";
	}
	cout<<endl;
}
}