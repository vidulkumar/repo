#include<iostream>
#include<string>
#define size 20
using namespace std;
int len(char str[])
{
	int i=0;
	while(str[i]!=0)
	{
		i++;
	}
	return i;
}
int* input();
int main()
{   int arr[size];
    arr = input();
    cout<<"function completed";
    cout<<*arr;
	return 0;
}

int * input()
{  char ch[size];
    int num[size];
    int length;
	cin>>ch;
	//length=sizeof(ch)/sizeof(ch[0]);
	//length=*(&ch + 1) - ch;
	//length=ch.length();
	//strcpy();
	length=len(str);
	cout<<"length is"<<length;
	cout<<"entering loop";
	for(int i=0;i<length;i++)
	{ 
	 num[i]=ch[i]-48;
	}
	cout<<"loop executed";
	return num;
}
