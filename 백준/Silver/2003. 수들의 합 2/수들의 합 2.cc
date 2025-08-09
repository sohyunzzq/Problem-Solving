#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	long long m;
	cin >> n >> m;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<long long> sum(n + 1, 0);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + arr[i - 1];

	int cnt = 0;

	int left = 0, right = 0;
	while (left <= right && right <= n) {
		long long temp = sum[right] - sum[left];
		if (temp == m) {
			cnt++;
			left++;
		}
		if (temp < m)
			right++;
		else if (temp > m)
			left++;
	}

	cout << cnt;
}