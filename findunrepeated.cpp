int Solution::singleNumber(const vector<int> &A) {
   int var1=0,var2=0;
   int temp,temp2,temp3,temp4;
   for(int i=0;i<A.size();i++)
   {   //cout<<" i "<<i<<endl;
       for(int j=0;j<32;j++)
       {
           temp= pow(2,j);//set jth bit
           
           temp2= A[i]&temp; //check if jth bit if variable is set
           
           if (temp2==0) // if jth bit was not set
           {
               continue;
           }
           else
           {
               temp3 = var1&temp;
               temp4 = var2&temp;
               if(temp3==temp&&temp4==temp)//if jth bit of both variable was set
                {
                    var1= var1 & (~temp);
                    var2= var2 & (~temp);
                }
                else if(temp3==temp)
                {  //cout<<"case1";
                    var2 = var2|temp;
                }else
                {   //cout<<"case2";
                    var1 = var1|temp;
                }
                //cout<<temp<<":"<<temp2<<":"<<temp3<<":"<<temp4<<"|"<<var1<<" "<<var2<<endl;
           }
       }
   }
    return var1;
}
