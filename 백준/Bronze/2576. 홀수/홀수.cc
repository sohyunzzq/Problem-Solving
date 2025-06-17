#include <iostream>
using namespace std;

int main() {
	int min_val = 100;
	int sum = 0;

	for (int i = 0; i < 7; i++) {
		int num;
		cin >> num;

		if (num % 2 == 1) {
			min_val = min(min_val, num);
			sum += num;
		}
	}

	if (sum == 0)
		cout << -1;
	else {
		cout << sum << endl << min_val;
	}
}