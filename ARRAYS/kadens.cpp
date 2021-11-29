#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int kadens( int a[] , int n)
{
	int maxSum=INT_MIN;
	int msf=a[0];
	for(int i=1;i<n;i++)
	{
		msf =msf  + a[i];
		if(msf<a[i])
		{
			msf = a[i];
		}
		if(msf>maxSum)
		{
			maxSum = msf;
		}

	}
	return maxSum;

}

int kadensdp(int a[],int n)
{
	int maxSum = INT_MAX;
	int maxSoFar = a[0];

	for(int i=1;i<n;i++)
	{
		maxSoFar = max(maxSoFar+a[i] ,a[i] );
		maxSum = max(maxSoFar , maxSum);

	}

	return maxSum;

}
int main()
{
	int arr[5] = {3,5,-10,4};
	cout<<kadens(arr,4);

	return 0;
}
