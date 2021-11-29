//Naive Approach-using two for loops
void twoOddOccurring(vector<int> arr,int n)
{
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
                cnt+=1;
        }

        //if count is odd
        if(cnt&1)
           cout<<arr[i]<<endl;
    }
}

//Efficient Approach--XOR of all elements = a^b where a,b occurs odd number of times
void twoOddOccurring(vector<int> arr, int n)
{
    int XOR=0,res1=0,res2=0;

    //Find XOr of all elements
    for(int i=0;i<n;i++)
        XOR^=arr[i];

    //Find RSB of XOR
    int RSB = XOR & (XOR-1);

    //Group elements based on RSB and arr[i]
    for(int i=0;i<n;i++)
    {
        if(arr[i] & (RSB)!=0)
            res1 = res1^arr[i];
        else
            res2 = res2^arr[i];
    }

    cout<<res1<<" "<<res2<<endl;
}