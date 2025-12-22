#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	int arr[10];
	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 10; i++)
			cin >> arr[i];

		sort(arr, arr + 10, greater<>());

		cout << arr[2] << endl;
	}
}