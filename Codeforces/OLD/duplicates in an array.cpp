
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

/*
vector<int>find_dup( vector<int> a)
{
    vector<int> v;
    sort(a.begin(),a.end());        //O(nlogn)
    for(int i=0;i<a.size();i++){    //O(n)
        if(a[i]==a[i+1]){
            v.push_back(a[i]);
        }
    }
    return v;
}

int main()
{
    vector<int> a={1,2,3,2,1};
    vector<int> sol=find_dup(a);
    for(int i=0;i<sol.size();i++){
       cout<<sol[i]<<" ";
    }
    return 0;
}
*/

/*

//O(n) O(1)
vector<int> find_dup(vector<int>&nums)
{
    vector<int>res;
    for(int i=0;i<nums.size();i++)
    {
        while(nums[i]!=nums[nums[i]-1])
            swap(nums[i],nums[nums[i]-1]);
    }
        for(int i=0;i<nums.size();i++)
    {
           if(nums[i]!=i+1)
            res.push_back(nums[i]);
    }
    return res;
}

int main()
{
    vector<int> a={4,3,2,7,8,2,3,1};
    vector<int> sol=find_dup(a);
    for(int i=0;i<sol.size();i++){
       cout<<sol[i]<<" ";
    }
    return 0;
}
*/

//when find a number i, flip the number at position i-1 to negative
//if the number at position at i-1 is already negative, i is the number that occurs twice
//alters input array

vector<int> find_dup(vector<int> nums)
{
    vector<int> res;
    for(int i=0;i<nums.size();i++)
    {
        int index= abs(nums[i])-1;
        if(nums[i]<0)
            res.push_back(abs(index+1));
        nums[index]=-nums[index];
    }
    return res;
}

int main()
{
    vector<int> a={4,3,2,7,8,2,3,1};
    vector<int> sol=find_dup(a);
    for(int i=0;i<sol.size();i++){
       cout<<sol[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<a.size();i++){
       cout<<a[i]<<" ";
    }
    return 0;
}
