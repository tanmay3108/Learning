#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<map>
using namespace std;

map<int, int> hm;
void subarrayWithSumK(int arr[], int n, int k)
{
    int sumSoFar=0;
    for(int i=0;i<n;i++)
    {
        sumSoFar = sumSoFar + arr[i];
        int extraSum = sumSoFar-k;
        if(hm.find(extraSum)!=hm.end())
        {
            std::cout <<"Subarry found at"<<hm[extraSum]+1+1<<"And ends at " <<i+1<< std::endl;
            break;
        }
        hm[sumSoFar]=i;
    }
}
 int main()
 {
     //int arr[] = {1, 4, 20, 3, 10, 5},sum = 33;
     int arr[] = {10, 2, -2, -20, 10}, sum = -10;
     int n = sizeof(arr)/sizeof(arr[0]);
     subarrayWithSumK(arr, n, sum);
 }