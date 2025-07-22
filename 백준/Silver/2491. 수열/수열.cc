#include <iostream>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(0);

int main() {
	fastio;

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = 1;
	// <=
	// DP_GE[i] = i번째 원소가 끝 원소일 때 가장 긴 길이
	vector<int> DP_GE(n, 1);
	for (int i = 1; i < n; i++) {
		if (arr[i] >= arr[i - 1]) {
			DP_GE[i] = DP_GE[i - 1] + 1;
			ans = max(ans, DP_GE[i]);
		}
	}
	
	// >=
	vector<int> DP_LE(n, 1);
	for (int i = 1; i < n; i++) {
		if (arr[i] <= arr[i - 1]) {
			DP_LE[i] = DP_LE[i - 1] + 1;
			ans = max(ans, DP_LE[i]);
		}
	}

	cout << ans;
}