#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int Ros = 6;
int Cols = 6;
int arr[6][6] = 
{
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0}
    
};


bool isValid(int x,int y)
{
    if((x>=6||x<0)||(y>=6||y<0))
    return false;
    return true;
}

int steps = 1000000;
bool isVisted(int x,int y)
{
    if(arr[x][y]==1)
    return true;
    else
    return false;
}
    int xi[] = {-2, -1, 1, 2, -2, -1, 1, 2};
	int yi[] = {-1, -2, -2, -1, 1, 2, 2, 1};

int minKnightStepsToReachDestination(int sx,int sy,int dx,int dy)
{
    
    if((sx == dx)&&(sy == dy))
    {
      cout<<"reached";    
      arr[sx][sy] = 1;
      return 0;    
    }
    
    
      arr[sx][sy] = 1;
       for(int i =0;i<8;i++)
       {
           
           
           if((isValid(sx+xi[i],sy+yi[i]))&&(!isVisted(sx+xi[i],sy+yi[i])))
           {
            int a = 1+minKnightStepsToReachDestination(sx+xi[i],sy+yi[i],dx,dy);
           if(a<steps)
           steps = a;    
           }
           
           
       }
       return steps;
}
int main() {
   
    //std::cout << minKnightStepsToReachDestination(1,5,5,5) << std::endl;
    minKnightStepsToReachDestination(1,3,5,0);
    cout<<steps;
	// your code goes here
	return 0;
}
