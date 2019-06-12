void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int bindex = 0,aindex=A.size();
    int sz = A.size()+B.size();
    A.resize(sz);
    for(int i=0;i<sz,bindex<B.size();i++)
    {   
        if(A[i]>B[bindex])
        {
            //cout<<"case1"<<endl;
            for(int j=sz-2;j>=i;j--)
            {
                A[j+1]=A[j];
            }
            A[i]=B[bindex];
            bindex++;
        }
        else if(B[bindex]>=A[aindex-1])
        {
            //cout<<"case2"<<endl;
            break;
        }/*
        for(int k=0;k<sz;k++)
        {
            cout<<A[k]<<" ";
        }
        cout<<endl;*/
    }
    aindex= aindex+bindex;
    while(aindex<A.size()&&bindex<B.size())
    {
        A[aindex] = B[bindex];
        aindex++;
        bindex++;
        
    }
    
}
