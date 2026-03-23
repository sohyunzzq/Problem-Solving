#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int k, n;
	cin >> k >> n;

	cout << n + 1 << " " << k * n + 1;
}