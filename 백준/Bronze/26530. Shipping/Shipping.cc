#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	cout << fixed;
	cout.precision(2);

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;

		double sum = 0;
		for (int i = 0; i < n; i++) {
			string name;
			int price;
			double num;

			cin >> name >> price >> num;

			sum += price * num;
		}
		cout << "$" << sum << endl;
	}
}