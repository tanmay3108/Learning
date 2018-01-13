#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
string powers(string ch,int p)
{
 
   string x;
for (int i = 0; i < p; ++i)
 {
    x=x+ch;
 } 
 return x;
}


string base(string str)
{
	string 
	y="";
	for(int i=0;i<str.length();i++)
	{
      y=y+str[i];
      string z=powers(y,int(str.length()/(i+1)));
      if(z.compare(str)==0)
      return y;
	}
	return str;



}	
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	
	string s1;
	string s2;	
	cin>>s1;
	cin>>s2;
	s1=base(s1);
	s2=base(s2);
	if(s1.compare(s2)==0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

	}
	
	return 0;
}
