#include<iostream>
#include<vector>
using namespace std;

int main()
{

    int n,min=100;
    int count=0;
    cin>>n;
    vector<int> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if (abs(a[i]-a[j])<=min)
            {
                min=abs(a[i]-a[j]);
                cout<<min<<" ";
                count+=1;
            }

        }
    }

    cout<<min<<" "<<count;

    return 0;
}
