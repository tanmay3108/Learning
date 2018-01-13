/* minimum number of steps required to reduce number to 1 by following *steps n-1,n/2,n/3 
*/


#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int arr[101];
int minimumNumber(int n)
{
    if(arr[n]!=-1)
    return arr[n];
    if(n==1)
    return 0;
    if(n<1)
    return INT_MAX;
    
    if(n%3 == 0)
    return 1+min(min(minimumNumber(n-1),minimumNumber(n/2)),minimumNumber(n/3));
    if(n%2 == 0)
    return 1+min(minimumNumber(n-1),minimumNumber(n/2));
    else
    return 1+minimumNumber(n-1);
    
}

int main() {


	for(int i=0;i<=100;i++)
	arr[i] = -1;
	for(int i=1;i<=100;i++)
	{
	    arr[i] = minimumNumber(i);
	}
	
	cout<<arr[100]<<endl;
	cout<<arr[25]<<endl;
	cout<<arr[99]<<endl;
	cout<<arr[50]<<endl;
	cout<<arr[11]<<endl;
	cout<<arr[1]<<endl;
	cout<<arr[5]<<endl;
	return 0;
	
}
