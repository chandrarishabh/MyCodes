#include<iostream>
using namespace std;
void Max_Heapify(int A[], int n, int i) //downward direction
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l < n && A[l] > A[largest])
		largest = l;
	if (r < n && A[r] > A[largest])
		largest = r;
	if (largest != i) {
		swap(A[i], A[largest]);
		Max_Heapify(A, n, largest);
	}
}
void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--) // building the heap (rearrange array)
		Max_Heapify(arr, n, i);
	for (int i = n - 1; i > 0; i--) {
		swap(arr[i], arr[0]);
		Max_Heapify(arr, i, 0);
	}
}
int main()
{
	int arr[] = {9, 7, 5, 1, 3, 4, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, n);
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
}