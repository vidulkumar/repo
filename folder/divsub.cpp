#include<iostream>
using namespace std;
int fun();
int main() {
    int n,arr[10];
    cin>>n;
    for(int i=0;i<n;i++)
        arr[i]=fun();
    
    for(int j=0;j<n;j++)
        cout<<arr[j];
        
	return 0;
}

int fun()
{
    int num,arr[100000],sum,ret=0;
    cin>>num;
    for(int i=0;i<num;i++)
        cin>>arr[i];
    for(int j=1;j<num;j++)
       { for(int k=0;k<num-j;k++)
            {sum=0;
            for(int l=0;l<=j;l++)
                sum=sum+arr[l];
            if(sum%num==0)
               ret++; 
                
            }
       }
    return ret;        
}
