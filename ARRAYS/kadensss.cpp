#include<iostream>
using namespace std;


int kadens ( int a[] , int n)
{
	int sum =0;
	int maxSum =0;
	for(int i=0;i<n;i++)
	{
	
		for(int j=i;j<n;j++)
		{
			for(int k=i;k<=j;k++)
			{
				sum+=a[k];
			}
			maxSum = max(sum,maxSum);
			sum=0;
		}
		
	}
	return maxSum;
}

int kadenspep(int a[] , int n)
{
	int maxSum = INT_MIN;
	int msf = a[0];
	for(int i=1;i<n;i++)
	{
		//Kepp joining
		msf = msf + a[i];

		//If a[i] is rich becomes independent
		if(msf<0)
		{
			msf = a[i];
		}

		//update maxSum
		maxSum = max(msf , maxSum);
		
	}

}

int main()
{	
	int a[] = {3,5, -10 ,4};

	cout<<kadens(a,4)<<endl;
	cout<<kadenspep(a,4)<<endl;
	return 0;
}
