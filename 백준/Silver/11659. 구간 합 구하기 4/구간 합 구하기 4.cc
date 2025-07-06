#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
	fastio;

	int n, m;
	cin >> n >> m;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	// 누적합 구하기
	vector<long long> sum(n + 1);
	sum[0] = nums[0];
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + nums[i - 1];

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		a--; b--;
		cout << sum[b + 1] - sum[a] << endl;
	}
}