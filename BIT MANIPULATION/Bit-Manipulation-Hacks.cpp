#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int k){
    return n & (1LL<<k)?1:0;
}

int setBit(int n,int k){
    return n | (1LL<<k);
}

int clearBit(int n,int k){
    return n & (~(1LL<<k));
}

int toggleBit(int n,int k){
    return n ^ (1LL<<k);
}

int off_RightMost_SetBit(int n){
    return n & (n-1); //or n & -n
}

int on_RightMost_0Bit(int n){
    return n | (n+1);
}

int isolate_RightMost_SetBit(int n){
    return n & (~n);
}

int isolate_RightMost_0Bit(int n){
    return ~n & (n+1);
}

int rightPropogate_RightMost_SetBit(int n){
    return n | (n-1);
}

int odd_or_even(int n){
    cout<< (n&1) ? "odd" : "even";
}

int main()
{
	int n,k;
    cin>>n>>k;

    cout<<getBit(n,k)<<endl;
    cout<<setBit(n,k)<<endl;
    cout<<clearBit(n,k)<<endl;
    cout<<toggleBit(n,k)<<endl;
    cout<<endl;

    cout<<off_RightMost_SetBit(n)<<endl;
    cout<<on_RightMost_0Bit(n)<<endl;
    cout<<endl;
    
    cout<<isolate_RightMost_SetBit(n)<<endl;
    cout<<isolate_RightMost_0Bit(n)<<endl;
    cout<<rightPropogate_RightMost_SetBit(n)<<endl;
    
    return 0;
}
