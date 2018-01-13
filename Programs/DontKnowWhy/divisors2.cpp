#include<iostream>
#include<cmath>
using namespace std;



 int main()
 {

    int t;
    cin>>t;
    while(t--)
    {
 	int n;
 	cin>>n;
 	int x=1;
 	int count=1;	
 	int z=0;
    
 	while(x)
 	{

     z=z+(n/(pow(5,count)));
     x=n/(pow(5,count));
     count++;
 	}

 	cout<<endl<<z<<endl;
 }
 }
