#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n,i;
    cin>>n;
    int *ptr=new int[n];
    
    for(i=0;i<n;i++){
        cin>>ptr[i];
    }
    for(i=n-1;i>=0;i--){
        cout<<ptr[i]<<" ";
    }
    
	delete[] ptr;
    ptr=nullptr;
    
    return 0;
}

