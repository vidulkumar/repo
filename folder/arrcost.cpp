#include<iostream>
using namespace std;
int fun();
int main() {
    int num,ar[10];
    cin>>num;
    for(int i=0;i<num;i++)
    {
        ar[i]=fun();
    }
    for(int i=0;i<num;i++)
    {
        cout<<ar[i]<<endl;
    }
    
	return 0;
}
int fun()
{
    int number,num[100000],retval=0;
    cin>>number;
    cin>>num[0];
    for(int i=1;i<number;i++)
    { cin>>num[i];
      for(int j=0;j<i;j++)
      {  if (num[i]<num[j])
          retval++;
      }
    }
    return retval;
}
