#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;

		int coins[10];
		bool badflag = false;
		for (int j = 0; j < d; j++) {
			cin >> coins[j];
		}
		
		for (int j = 1; j < d; j++) {
			if (coins[j] < coins[j - 1] * 2)
				badflag = true;
		}

		cout << "Denominations: ";
		for (int j = 0; j < d; j++)
			cout << coins[j] << " ";
		cout << endl;
		cout << (badflag ? "Bad " : "Good ") << "coin denominations!" << endl << endl;
	}
}