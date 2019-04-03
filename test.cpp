#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;

int main()
{
string str;
string key;	
int k[3][3]; 
cin>>str;
cin>>key;

if((str.length()%3)!=0)
	{str.resize(str.length()+3-(str.length()%3),'Z'); }
  if(key.length()!=9)
  {  key.resize(9,'Z'); }
cout<<"string : "<<str<<endl;
cout<<"Key    : "<<key<<endl;

int m=0, pt[3][str.length()/3];
for(int i=0;i<3;i++)
  {
	for(int j=0;j<3;j++)
	{
       k[i][j]= key[m++];
	}
  }
m=0;
 for(int i=0;i<3;i++)
  {
	for(int j=0;j<str.length()/3;j++)
	{
       pt[i][j]= str[3*j+i]; 
  } 
}

for(int i=0;i<3;i++)
  {cout<<endl;
	for(int j=0;j<3;j++)
	{
       cout<<k[i][j]<<" ";
	}
  }
  cout<<endl;
 for(int i=0;i<3;i++)
  {cout<<endl;
	for(int j=0;j<str.length()/3;j++)
	{
       cout<<pt[i][j]<<" ";
	}
  } 
 for(int i=0;i<3;i++)
  {cout<<endl;
	for(int j=0;j<str.length()/3;j++)
	{
       cout<<"["<<i<<","<<j<<"]";
	}
  }  




}