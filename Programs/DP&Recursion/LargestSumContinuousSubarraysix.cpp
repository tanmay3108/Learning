#include<iostream>
using namespace std;
 
 void getMAxSumSubarry(int arr[],int n)
{
    int max=-1;
    int sum=0;
    int start=-1;
    int end=-1;
    int pos;
    //{-2,1,-3,-4,-5,-4,-8,-10};
    for(int i=0;i<n;i++)
    {
      if(sum==0){
          pos = i;
          
      }
      sum=sum+arr[i];
      if(sum<0){
          sum=0;
          continue;
          
      }
      if(sum>max)
      {   
          start=pos;
          max=sum;
          end=i;
      }
      
    }
    
    cout<<"Max sum is"<<max<<endl<<"Starting at"<<start<<endl<<"Ending at"<<end<<endl;
}


int main()
{
    
 int arr[]={-2, -3, -4, 0, -1, -2, -1, -5, -3};
 int n = sizeof(arr)/sizeof(arr[0]);
 getMAxSumSubarry(arr,n);
 
    
}
