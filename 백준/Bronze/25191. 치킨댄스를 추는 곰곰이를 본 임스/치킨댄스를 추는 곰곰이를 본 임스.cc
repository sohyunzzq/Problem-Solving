#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;

	int cnt = 0;
	cnt += a / 2 + b;

	cout << (cnt > n ? n : cnt);
}