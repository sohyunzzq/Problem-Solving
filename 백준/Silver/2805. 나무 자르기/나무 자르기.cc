#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int left = 0;
	int right = arr[n - 1];

	int ans;

	while (left <= right) {
		int mid = (left + right) / 2;
		long long tmp = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid)
				tmp += arr[i] - mid;
		}

		if (tmp >= m) {
			ans = mid;
			left = mid + 1;
		}
		else if (tmp < m) {
			right = mid - 1;
		}
	}

	cout << ans;
}