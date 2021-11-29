//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
      //TopDown
    int CountSubsetSum(vector<int> arr, int n, int sum)
    {
        //dp table
        int t[n+1][sum+1];

        //BaseCase--> Initialization of first row first column
        //(n,sum)=>(i,j)
        //n==0 and sum>0 ->false
        //n>=0 and sum==0 ->true empty subset{} gives sum 0 for any n


        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                    t[i][j] = 0;
                if(j==0)
                    t[i][j] = 1;
            }
        }

        //ChoiceDiagram-->Recursive->Iterative

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                //if (n-1)th number is less than sum we can include or exclude
                if(arr[i-1]<=j)
                    t[i][j] = (t[i-1][j-arr[i-1]]) + (t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        }

        return t[n][sum];
    }

    int countDiff(vector<int> arr, int n, int diff)
    {
        int arraysum =0;
        for(int i=0;i<n;i++) arraysum+=arr[i];


        int sum = (diff + arraysum)/2;

        if((diff+arraysum)&1) return 0;
        return CountSubsetSum(arr , n ,sum);
    }

    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        return countDiff(A , A.size() , target);

    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;
        vector<int>arr(N);

        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends
