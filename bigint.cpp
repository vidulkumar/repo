#include<iostream>
using namespace std;
class BigInteger
{   int *arr;
    int len;

    public:
        BigInteger()
        {
            arr=nullptr;
            len=0;
        }
        ~BigInteger()
        {
            delete [] arr;
            arr=nullptr;
        }

        void input();
        void print();
        BigInteger operator+(const BigInteger& B);

};
void BigInteger::input()
        {  string str;

            cin>>str;
            len=str.length();
            arr= new int[len];
            for(int i=0;i<len;i++ )
                {
                    arr[i]=str[i]-48;
                }
        }
void BigInteger::print()
    {   cout<<"\n length is : "<<len<<endl;
        for(int j=0;j<len;j++ )
        {
            cout<<"["<<j<<"] "<<arr[j];
            cout<<endl;
        }
    }

BigInteger BigInteger:: operator+(const BigInteger& B)
    {
        BigInteger O;
        int flag;
        if(B.len>this->len)
        {
            O.len=B.len+1;
            flag=2;
        }
        else
        {
            O.len=(this->len)+1;
            flag=1;
        }
        O.arr = new int [O.len];
        for(int i=0;i<=O.len;i++)
            {O.arr[i] = 0;}
         //   O.print();

        for(int j=O.len-1,k=len-1,m=B.len-1;k>=0&&m>=0;j--,k--,m--)
        {   //cout<<"\narr["<<k<<"] ="<<arr[k];
            //cout<<"\tB.arr["<<m<<"] ="<<B.arr[m];
            //cout<<"\tO.arr["<<j<<"] ="<<O.arr[j];
            O.arr[j]=O.arr[j]+arr[k]+B.arr[m];
            if(O.arr[j]>=10)
               {

                O.arr[j]=O.arr[j]-10;
                O.arr[j-1]=O.arr[j-1]+1;
               }
              // cout<<"\t=O.arr["<<j<<"] ="<<O.arr[j];
        }
       // O.print();
        if (flag==2)
        {
            for(int n=B.len-len,q=n-1;q>=0;n--,q--)
            {
                //cout<<"\nB.arr["<<n<<"] ="<<B.arr[q];
                //cout<<"\tO.arr["<<q<<"] ="<<O.arr[n];
                O.arr[n]=O.arr[n]+B.arr[q];
                //cout<<"\t=O.arr["<<n<<"] ="<<O.arr[n];
            }
            //O.arr[0]=0;

        }
        else
        {
            for(int p=len-B.len,r=p-1;r>=0;p--,r--)
            {   //cout<<"\narr["<<r<<"] ="<<arr[r];
               // cout<<"\tO.arr["<<p<<"] ="<<O.arr[p];
                O.arr[p]=O.arr[p]+arr[r];

                //cout<<"\t=O.arr["<<p<<"] ="<<O.arr[p];
            }
            //O.arr[0]=0;
        }
        //if(O.arr[0]==0)
         //  O.len=O.len-1;
        O.print();
     return O;
    }

int main()
{
    BigInteger a,b,c;
    cout<<"enter a number : ";
    a.input();
    cout<<"\nenter a number : ";
    b.input();
    c= a + b;
    cout<<"\n sum is  : ";
    c.print();
    cout<<endl;
    a.print();
    return 0;
}
