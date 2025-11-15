#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int c4, a3, a4;
	cin >> c4 >> a3 >> a4;

	cout << fixed;
	cout.precision(6);

	double sum = 0;
	sum += 2.29 * 3.24 * c4 * 2;
	sum += 2.97 * 4.20 * a3 * 2;
	sum += 2.10 * 2.97 * a4;

	cout << sum * 0.01;
}