#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	long long n, m, price;
	cin >> n >> m >> price;

	long long p1 = (m + 1) * price * (100 - n) / 100;
	long long p2 = m * price;

	cout << min(p1, p2);
}