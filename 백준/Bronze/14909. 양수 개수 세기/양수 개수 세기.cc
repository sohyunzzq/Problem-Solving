#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	int cnt = 0;

	while (cin >> n)
		if (n > 0)
			cnt++;
	cout << cnt;
}