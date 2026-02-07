#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

vector<int> arr;

void Binary(int n) {
	while (n) {
		arr.push_back(n % 2);
		n /= 2;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;

		arr.clear();

		Binary(n);
		for (int i = 0; i < arr.size(); i++)
			if (arr[i])
				cout << i << " ";

		cout << endl;
	}
}