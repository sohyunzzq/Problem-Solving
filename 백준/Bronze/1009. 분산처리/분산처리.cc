#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;

		int res = a % 10;
		for (int j = 0; j < b - 1; j++) {
			res *= a;
			res %= 10;
		}

		cout << (res == 0 ? 10 : res) << endl;
	}
}