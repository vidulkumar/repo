void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int bindex = 0,aindex=A.size();
    
    for(int i=0;i<A.size(),bindex<B.size();i++)
    {   
        if(A[i]>B[bindex])
        {
            
            A.insert(A.begin()+i,B[bindex]);
            bindex++;
        }
        else if(B[bindex]>=A[aindex-1])
        {
            //cout<<"case2"<<endl;
            break;
        }

    }

    while(bindex<B.size())
    {
        A.push_back(B[bindex]);
        bindex++;
    }
    
}
