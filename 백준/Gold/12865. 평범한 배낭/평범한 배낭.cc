#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> weight;
vector<int> value;
vector<vector<int>> DP;

int main() {
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;

		weight.push_back(w);
		value.push_back(v);
	}

	// n X (k+1) DP table
	DP.resize(n);
	for (int i = 0; i < n; i++)
		DP[i].resize(k + 1);

	// 0열은 전부 0
	for (int i = 0; i < n; i++)
		DP[i][0] = 0;

	int max_val = 0;

	// 0번 보석은 따로 채워주기
	for (int j = 0; j <= k; j++)
		DP[0][j] = 0;
	// 아무것도 못 넣는 경우
	if (k >= weight[0]) {
		DP[0][weight[0]] = value[0];
		max_val = max(max_val, value[0]);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			// 현재 무게가 j보다 크면 못 넣음 -> 바로 위 거
			if (weight[i] > j) {
				DP[i][j] = DP[i - 1][j];
				max_val = max(max_val, DP[i][j]);
			}
			// 넣을 수 있다면, 넣는 게 이득인지 안 넣는 게 이득인지
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - weight[i]] + value[i]);
				max_val = max(max_val, DP[i][j]);
			}
		}
	}

	cout << max_val;
}