#include<iostream>
#include<algorithm>

using namespace std;


/*--------------------------------------🙄InsertionSort🙄---------------------------------------------*/

void InsertionSort(int a[],int n)
{
	//Loop through the array from a[1...n-1]
	//Assume a[0] as the sorted array

	for (int  i = 1; i < n; i++)
	{
	    //Loop j from i to 1 if current element less than previous element swap them
		for(int j=i; j>0 && a[j]<a[j-1]; j--)
		{
			swap(a[j],a[j-1]);
		}
	}

	return;
}

/*--------------------------------------🤔SelectionSort🤔---------------------------------------------*/

void SelectionSort(int a[], int n)
{

	//Loop from a[0...n-2]
	for (int i = 0; i < n-1; i++)
	{
		//Choose starting position i as  index of min element
		int min=i;

		//Check the rest of the array a[i+1...n-1]
		for(int j=i+1;j<n;j++)
		{
			//if I find any element a[j] < a[i] means a[j] is min element then j is the index of min element
			if(a[j]<a[i])
				min=j;
		}

		//Swap the min elementa[j] to its correct position or a[i]
		swap(a[min],a[i]);
	}
}

/*--------------------------------------💦BubbleSort💦---------------------------------------------*/

void BubbleSort(int a[],int n)
{

    //Loop from 0..n-2
	for(int i=0;i<n-1;i++)
	{
	    //Loop from 0..n-2-i
		for(int j=0;j<n-1-i;j++)
		{
		    //If j+1th element is less than jth element swap them
			if(a[j+1]<a[j])
				swap(a[j],a[j+1]);
		}
	}
}

/*--------------------------------------🏃‍♂️🏃‍♂️QuickSort🏃‍♂️🏃‍♂️---------------------------------------------*/


int Partition(int a[],int low,int high)
{
	//Assume first element i.e a[low] as pivot
	int pivot=a[low];

	//i-->low j-->high
	int i=low;
	int j=high;


	do{

        //Keep moving i towards the right until I  find an elemnt a[i] GREATER than or EQUAL to the pivot element
        do{i++;}while(a[i]<pivot);

        //Keep moving j towards the left until I find an element a[j] LESSER than or EQUAL to the  pivot element
        do{j--;}while(a[j]>pivot);

        //IF i and j do not cross each other swap a[i] and a[j]
        if(i<j) swap(a[i],a[j]);

	} while(i<j);  //i and j do not cross each other

	//Swap the first element(a[low]) and pivot element(a[j])
	swap(a[low],a[j]);

	//Return the index of pivot element
	return j;

}


void QuickSort(int a[],int low,int high)
{
	//If the problem is big
	//Array size > 2
	if(low<high)
	{
		//Find the index j of the pivot by Partitioning the array a[low...high+1]
		int j=Partition(a,low,high+1);

		//Sort the left part before the pivot element i.e a[low...j-1]
		QuickSort(a,low,j-1);

		//Sort the right part after the pivot element i.e a[j+1...high]
		QuickSort(a,j+1,high);
	}
	return ;
}


/*--------------------------------------------------📎MergeSort📎------------------------------------------------*/

//Merging
void Merge(int a[],int low,int mid,int high)
{
	int i,j,k;
	int b[50];

	//Comparing and copying
	for(i=low,j=mid+1,k=low; i<=mid && j<=high;)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}

	//If First array is exhausted
	while(i<=mid)
		b[k++]=a[i++];

	//If second array is exhausted
	while(j<=high)
		b[k++]=a[j++];

	//Copy everything from b[] back to a[]
	for(int i=low;i<=high;i++) a[i]=b[i];

	return ;
}


//MergeSort
void MergeSort(int a[],int low,int high)
{
	//If the problem is large
	//array of size > 2
	if(low<high)
	{
		//Divide the array
		int mid=(low+high)/2;

		//Sort First array a[low..mid]
		MergeSort(a,low,mid);

		//Sort Second array a[mid+1...high]
		MergeSort(a,mid+1,high);

		//Merge both the arrays
		Merge(a,low,mid,high);
	}
	return;
}

/*-----------------------------------------------------------MAIN--------------------------------------------*/

int main()
{
	int a[50],n;

	int choice;

	cout<<"\n 1:InsertionSort \n 2:SelectionSort \n 3:BubbleSort \n 4:MergeSort \n 5:QuickSort\n";
	cout<<"\n👉Enter the choice, array size and elements:\n";

	cin>>choice;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];

	switch(choice)
	{

	case 1: InsertionSort(a,n);
			break;

	case 2: SelectionSort(a,n);
			break;

	case 3: BubbleSort(a,n);
			break;

	case 4: MergeSort(a,0,n-1);
			break;

			//append int max at end of the array
			//It will be the pivot element at the correct position i.e it will be at the end of the array always
	case 5: a[n]=100000;
			QuickSort(a,0,n-1);
			break;

	default: cout<<"\n";
			 break;

	}

	for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;

	return 0;
}
