#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n, m;
		cin >> n >> m;

		cout << "#" << tc << " ";
		cout << (((m & ((1 << n) - 1)) == (((1 << n) - 1))) ? "ON" : "OFF");
		cout << '\n';
	}
}