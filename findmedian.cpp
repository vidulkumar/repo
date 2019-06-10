int elementAt(vector <vector<int> > &vect,int n)
{   //if(n==0)
      // return vect[0][0];
    
    int j=n%vect[0].size();
    int i=n/vect[0].size();
    //cout<<"n:"<<n<<" i:"<<i<<" j:"<<j<<endl;
    return vect[i][j];
}
void setElementAt(vector <vector<int> > &vect,int n,int val)
{   
    
    int j=n%vect[0].size();
    int i=n/vect[0].size();
    vect[i][j]=val;
    return;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int size = A.size()*A[0].size(), j,key;

     for(int i=1;i<size;i++)
     {
         j = i-1;
         key = elementAt(A,i);
         //cout<<"key: "<<key<<" \n";
         while(j>=0 && elementAt(A,j)>key )
         {
             setElementAt(A,j+1,elementAt(A,j)); 
             j--;
         }
         
         setElementAt(A,j+1,key);

     }
     
