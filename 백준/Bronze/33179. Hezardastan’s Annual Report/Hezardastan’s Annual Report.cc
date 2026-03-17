#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		cnt += num / 2;
		cnt += num % 2;
	}

	cout << cnt;
}