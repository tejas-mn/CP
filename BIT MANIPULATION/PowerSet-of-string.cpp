//Power Set generating using bitwise - O(2^n * n)
void PowerSet(string str)
{
    int n = str.size();
    int powSize  = pow(2,n);

    //For each counter(0 to 2^n -1) --O(2^n)
    for(int counter = 0 ;counter<powSize;counter++)
    {
        //For each j in str length(0 to n-1) --O(n)
        for(int j=0;j<n;j++)
        {
            //if there is set bit in counter print that position's char
            if((counter & (1<<j))!=0)
                cout<<str[j];
        }
        cout<<endl;
    }
}