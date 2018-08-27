#include<iostream>
using namespace std;
int main() {
    long int n,step_score[100000],alpha_score[100000]={0},journey_score=0;
    
	cin>>n;
	cin>>step_score[0];
	alpha_score[0]=0;
	for(long int i=1;i<n;i++)
	{
	    cin>>step_score[i];
	    
	   for(long int j=i-1;j>=0;j--)
	   { 
	       if(step_score[i]>step_score[j])
	           alpha_score[i-1]=alpha_score[i-1]+step_score[j];
	   }
	    
	}
	for(long int k=0;k<n;k++ )
	{
	    journey_score=journey_score+alpha_score[k];
	}
	cout << journey_score%1000000007;
	return 0;
}
