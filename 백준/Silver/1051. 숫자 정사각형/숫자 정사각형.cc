#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<char>> nums;

bool InRange(int x) {
	return 0 <= x && x < n;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	nums.resize(n);
	for (int i = 0; i < n; i++)
		nums[i].resize(m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> nums[i][j];
		}
	}

	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char num = nums[i][j];

			for (int col = 1; col < m; col++) {
				int len = col - j;

				if (InRange(i + len) &&
					num == nums[i][col] &&
					num == nums[i + len][j] &&
					num == nums[i + len][col])
					ans = max(ans, (len + 1) * (len + 1));
			}
		}
	}
	cout << ans;
}