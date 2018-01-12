#include<bits/stdc++.h>
using namespace std;

//merge two sorted halves
void mergeHalves(int* a, int left, int right, int middle)
{
	int x=left, y=middle+1;
	int temp[right-left+1];
	int k=0;
	while(x<=middle && y<=right)
	{
		if(a[x]<a[y])
		{
			temp[k]=a[x];
			k++;
			x++;
		}
		else
		{
			temp[k]=a[y];
			k++;
			y++;
		}
	}
	for(int i=x;i<=middle;i++)
	{
		temp[k]=a[i];
		k++;
	}
	for(int j=y;j<=right;j++)
	{
		temp[k]=a[j];
		k++;
	}
	for(int m=left, k=0;m<=right;m++,k++)
	{
		a[m]=temp[k];
	}

}

//divide array into two equal halves
void mergeSort(int* arr, int low, int high)
{
	if(low<high)
	{
		int middle = (low + high)/2;
		mergeSort(arr, low, middle);
		mergeSort(arr, middle+1, high);
		mergeHalves(arr, low, high, middle);
	}
}
int main()
{
	
}