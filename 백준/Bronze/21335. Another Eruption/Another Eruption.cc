#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	double a;
	cin >> a;

	cout << fixed;
	cout.precision(9);

	cout << 2 * sqrt(a / M_PI) * M_PI;
}