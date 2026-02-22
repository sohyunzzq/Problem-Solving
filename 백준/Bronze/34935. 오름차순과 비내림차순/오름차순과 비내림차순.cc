#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<long long> arr(n);
	bool flag = true;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++) {
		if (arr[i] <= arr[i - 1]) {
			flag = false;
			break;
		}
	}

	cout << flag;
}