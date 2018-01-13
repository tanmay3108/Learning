#include<iostream>
#include<cmath>
#define X 4
#define Y 4
#define FINISH 7
using namespace std;
int arr[100][100]={0};
int pos[100][3];
int visited[100][100]={0};

void display(int arr[100][100],int x,int y)
{
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++)
			cout<<arr[i][j];
		cout<<endl;
	}
}
bool valid(int i,int j)
{
	if(i>X||i<1||j>Y||j<1)
		return 0;
	if(visited[i][j]==1)
		return 0;
    if(arr[i][j]==5)
		return 0;	
	 return 1;
}

void print(int x,int y)
{
	if(arr[x][y]==FINISH)
		return;
if(valid(x,y))
{
	visited[x][y]=1;
	arr[x][y]=1;
	print(x+1,y);
	print(x-1,y);
	print(x,y+1);
	print(x,y-1);
	
}

else
return;

}

int main()
{
	arr[1][1]=1;
	arr[2][2]=5;
	arr[2][3]=5;
	arr[2][1]=5;
	arr[3][1]=5;
	arr[4][4]=7;
	visited[1][1]=-1;
	print(1,1);
	display(arr,X,Y);
return 0;
}