#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

#define N_SZ 8

bool IsPrime(int x) {
	for (int i = 2; i *i<= x; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> prime(N_SZ + 1);

	prime[1] = { 2, 3, 5, 7 };
	int arr[4] = { 1, 3, 7, 9 };

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < prime[i - 1].size(); j++) {
			int num = prime[i-1][j] * 10;

			for (int k = 0; k < 4; k++) {
				int tmp = num + arr[k];

				if (IsPrime(tmp))
					prime[i].push_back(tmp);
			}
		}
	}

	for (int i = 0; i < prime[n].size(); i++)
		cout << prime[n][i] << endl;
}