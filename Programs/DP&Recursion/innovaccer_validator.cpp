#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int na=10;
int a[]={1,0,1,1,0,1,0,1,0,0};
int validator(int V,int pos,int n)
{
  pos=pos+V;
  if(pos>=(n-1))
    return 1;
  if(a[pos]==0)
    return 0;
  return(validator(V,pos,n)||validator(V+1,pos,n)||validator(max(V-1,1),pos,n));
}

int main()
{
	
	cout<<validator(1,-1,na);
	return 0;
}
