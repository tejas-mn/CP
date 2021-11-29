#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int kadens(vector<int> v)
{
  int maxSoFar = v[0];
  int maxSum = v[0];

  for(int i=1;i<v.size();i++)
  {
	maxSoFar = max(v[i-1] + v[i] , v[i] );
	maxSum = max(maxSum,maxSoFar);
  }

  return maxSum;
}


int main()
{
        cout<<kadens({9,3,-10,4,5 });	
	return 0;
}
