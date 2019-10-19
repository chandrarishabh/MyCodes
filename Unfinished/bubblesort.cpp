#include <iostream>
using namespace std;
void inputarr(int arr[], int n)
{
	cout << "Enter " << n << " elements: \n";
	for (int i = 0; i < n; i++) cin >> arr[i];
}
void outputarr(int arr[], int n)
{
	cout << "The sorted array: \n";
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
void bubblesort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)break;
	}
}
int main() {
	int n;
	cout << "Enter no. of elements \n";
	cin >> n;
	int arr[100];
	inputarr(arr, n);
	bubblesort(arr, n);
	outputarr(arr, n);
}
