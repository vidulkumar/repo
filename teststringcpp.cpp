#include<iostream>
#define size 20
using namespace std;

int len(char str[]);
int main()
{   char str[20];
    int ch,a,b,c,d,l;
    cin>>str;
    l=len(str);
    cout<<"length is : "<<l;
	for(int i=0;i<size;i++)
	{
		cout<<str[i]<<"\n";
	}
	a=str[2];
	b=str[3];
	c=str[4];
	d=str[5];
	cout<<"-----";
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	cout<<d<<endl;
	return 0;
}

int len(char str[])
{
	int i=0;
	while(str[i]!=0)
	{
		i++;
	}
	return i;
}
