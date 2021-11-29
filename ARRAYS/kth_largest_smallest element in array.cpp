#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void swap(int *x , int *y)
{

	int temp = *x;
	*x = *y;
	*y = temp;

}

int Partition(int arr[] , int low , int high)
{
	int i = low;
	int j = high;

	int pivot = arr[high];

	while(i<=j)
	{
		while(arr[i]<=pivot){i++;}
		while(arr[j]>pivot){j--;}
		if(i<j)
            swap(&arr[i] ,& arr[j]);

	}

	swap(&arr[low] ,&arr[j]);

	return j;

}


void QuickSort(int arr[] , int low , int high , int k)
{
	if(low<high)
	{
		int j = Partition(arr , low , high);

		if(j==k){
            cout<<arr[k-1]<<endl;
		}
		else if(j<k){
            QuickSort(arr , low , j-1 , k);
		}
		else{
            QuickSort(arr , j+1 , high , k);
		}
	}
	return;

}




void kth_smallest(int arr[] , int n,  int k)
{
	QuickSort(arr , 0 , n-1,k);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	//cout<<endl;
	//return arr[k-1];
}


int main()
{
	int n;
	cin>>n;

	int arr[100];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int k;
	cin>>k;

	kth_smallest(arr, n , k);

	return 0;
}

