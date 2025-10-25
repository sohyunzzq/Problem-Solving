#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = arr[0];
	for (int i = n - 1; i > 0; i--) {
		if (arr[i] != arr[i - 1] + 1) {
			ans += arr[i];
		}
	}
	
	cout << ans;
}