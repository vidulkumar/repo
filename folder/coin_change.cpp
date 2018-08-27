#include<iostream>
using namespace std;
int fun(int list1[],int target,int index);
int main()
{
    int num,list2[250],target;
    cin>>target;
    cin>>num;
    for(int i=0;i<num;i++)
    {  cin>>list2[i]; }
    cout<<fun(list2,target,num-1);
    return 0;
 }
int fun(int list1[],int target,int index)
{

    int num=0;
    if (target==0)
        {//cout<<"returned 0 \n";
        return 0;}
    else if (index==0)
         {
             if (target%list1[0]==0)
             { //cout<<"returned 1\n";
               return 1;}
             else
                return 0;
             }
    else{
        //cout<<"executing for denomination for "<<list1[index]<<"\n";

        for (int i=0;i<(target/list1[index]+1);i++)
            {
              //  cout<<"for "<<i<<" "<<list1[index]<<"\n";
                num=num+fun(list1,target-(i*list1[index]),index-1);

             }
        if(target%list1[index]==0 )
            {
            //cout<<"added 1 \n";
            num=num+1;}
           }
    return num;
}
