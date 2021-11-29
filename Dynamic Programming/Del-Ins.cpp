#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
void *addr = memset(dp , -1 ,sizeof(dp));

int LCS(string a , string b , int m , int n)
{
    //Base Case : m->i n->j lcs =0 if i==j==0
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }

    //Choice Diagram
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] =  1 + dp[i-1][j-1];
            else
                dp[i][j] =  max(dp[i][j-1] , dp[i-1][j]);
        }
    }

    return dp[m][n];
}

string PrintLCS(string a , string b , int m, int n)
{
    string ans="";

    //Traverse from last cell so
    int i=m;
    int j=n;

    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            ans+=a[i-1];
            i--;j--;
        }
        else
        {
            if(dp[i][j-1]>dp[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    reverse(ans.begin() , ans.end());
    return ans;
}


int main()
{
    /****************************STDIN/STDOUT******************************/
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    /****************************STDIN/STDOUT******************************/

    string a,b;
    cin>>a>>b;

    int lcs_length = LCS(a,b, a.size() , b.size());
    string lcs= PrintLCS(a , b , a.size() , b.size());

    cout<<"#Del: "<<a.size() - lcs_length<<endl;
    cout<<"#Ins: "<<b.size() - lcs_length<<endl;

    return 0;
}
