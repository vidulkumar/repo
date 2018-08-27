#include<iostream>
using namespace std;
int gcd(int num1,int num2);
int main() {
    int num1,num2;
    cin>>num1;
    cin>>num2;
    cout<<gcd(num1,num2);
	return 0;
}

int gcd(int num1,int num2)
{  int num3;
    if(num2>num1)
    {num3=num1;
    num1=num2;
    num2=num3;}
    
    while(num2!=0)
    {   num3=num2;
        num2=num1%num2;
        num1=num3;
        
    }
    return num1;
    
}
