#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

string encrypt( string str,int key)
{
	std::transform(str.begin(), str.end(),str.begin(), ::toupper);
	for(int i=0;i<str.length();i++)
    {
	   str[i]=(str[i]-65+key)%26;
	   str[i]=str[i]+65;
    }
    return str;
}
string decrypt( string str,int key)
{	
    std::transform(str.begin(), str.end(),str.begin(), ::toupper);
	for(int i=0;i<str.length();i++)
    {
	   str[i]=(str[i]-65-key)%26;
       if(str[i]<0)
       	{str[i]=str[i]+26;}

	   str[i]=str[i]+65;
    }
    return str;
	

}
int main()
{   
	string str;
	int key;
	int choice;

	do{ 
		cout<<"\n--------TYPE TEXT IN CAPITAL ONLY---------"<<endl;
		cout<<"1. Encrypt a messege :"<<endl;
		cout<<"2. Decrypt a messege :"<<endl;
		cout<<"3. Exit."<<endl;
		cin>>choice;
	switch(choice)
	{	
	    case 1: 
	       cout<<"Enter a string : ";
	       cin>>str;
           cout<<"Enter a key : ";
           cin>>key;
           cout<<"Cipher text is : "<<encrypt(str,key)<<endl;
           break;
        case 2:
           cout<<"Enter Cipher text : ";
           cin>>str;
           cout<<"Enter the key : ";
           cin>>key;
           cout<<"Plain text is : "<<decrypt(str,key)<<endl;
           break;
 
       }
       }while(choice==1||choice==2);
   return 0;
   }    

