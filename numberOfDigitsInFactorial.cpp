#include<iostream>
#include<cmath>
using namespace std;
//Kamenetsky's Formula
long long int fact_optimized(int n) {
	if (n < 0) return 0;
	if (n <= 1) return 1;

	double x = ((n * log10(n / M_E) +  0.5 * log10(2 * M_PI * n) ));
	return floor(x) + 1;

}

long long int fact(int n) {
	if (n < 0) return 0;
	if (n <= 1) return 1;

	double res = 0;
	for (int i = 2; i <= n; i++) {
		res += log10(i);
	}
	return floor(res) + 1;
}
int main() {
	cout << fact(5) << " " << fact_optimized(5) << endl;
	cout << fact(10) << " " << fact_optimized(10) << endl;
	cout << fact(50) << " " << fact_optimized(50) << endl;
	cout << fact(100) << " " << fact_optimized(100) << endl;
}