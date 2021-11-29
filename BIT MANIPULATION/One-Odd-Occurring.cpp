
//Naive Approach-using two for loops
void oneOddOccurring(vector<int> arr,int n)
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


//Efficient Approach--XOR of all elements
void oneOddOccurring(vector<int> arr,int n)
{
    int res=0;
    for(int i=0;i<n;i++){
        //Cancels even occurring elements
        res^=arr[i];
    }
    cout<<res<<endl;
}
