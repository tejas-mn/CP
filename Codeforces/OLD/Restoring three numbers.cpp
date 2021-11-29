#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v(4);
    for(int &e:v)
    {
        cin>>e;
    }
    sort(v.begin(),v.end());
    cout<<v[3]-v[0]<<" "<<v[3]-v[1]<<" "<<v[3]-v[2];


    return 0;

}
