#include<bits/stdc++.h>
using namespace std;
//O(n + range) time
vector<int> pigeonholeSort(vector<int> A) {
	int MAX = 0, MIN = 0;
	int n = A.size();
	for (int i = 0; i < n; i++) {
		MAX = max(A[i], MAX);
		MIN = min(A[i], MIN);
	}
	int range = MAX - MIN + 1;

	vector<int> holes[range];
	for (int i = 0; i < n; i++) {
		holes[A[i] - MIN].push_back(A[i]);
	}

	int j = 0;
	for (int i = 0; i < range; i++) {
		for (auto it = holes[i].begin(); it != holes[i].end(); it++) {
			A[j++] = *it;
		}
	}
	return A;

}

int main()
{
	vector<int> A{4, 3, 7, 1, 2};
	vector<int> v = pigeonholeSort(A);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}