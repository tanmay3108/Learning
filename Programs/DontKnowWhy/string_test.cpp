#include<iostream>
#include<cstring>
using namespace std;
void display(string s)
{
	cout<<s;
}
int main()
{
	string s;
	string m="Tanmay";
	s="Tanmay";
	s=s+'a';
	cout<<s.length()<<endl;
	display(s);
	if(s==m)//Cannot make comparsion lik this
		cout<<"same";
	else
	cout<<"not same"<<endl;
s="Tanmay";
cout<<s.compare(m);
	return 0;
}
