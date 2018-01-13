#include <iostream>
using namespace std;


int mps(int arr[] ,int i,int n)
{
    if(i == n-1)
            return arr[i];
    if(i>=n)
    return 0;
    
    return max((arr[i]+mps(arr,i+2,n)),(arr[i+1],mps(arr,i+3,n)));
}

int main() {
    
    int arr[] ={5,3,4,11,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    std::cout << mps(arr,0,size) << std::endl;
	// your code goes here
	return 0;
}


