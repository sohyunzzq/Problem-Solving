#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> stair(n);
	for (int i = 0; i < n; i++)
		cin >> stair[i];

	// dp[n]: n번째 칸까지 밟았을 때 얻을 수 있는 최고 점수
	// n번째 칸에 오려면 (n-2)번째 밟거나 (n-1)번째 밟아서 올 수 있음
	// (n-1)번째 밟으면 (n-2)번째 못 밟음
	// dp[n] = max(dp[n-2], stair[n-1] + dp[n-3]) + stair[n]

	int dp[300] = {};
	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	dp[2] = max(stair[0], stair[1]) + stair[2];
	
	for (int i = 3; i < n; i++)
		dp[i] = max(dp[i - 2], stair[i - 1] + dp[i - 3]) + stair[i];

	cout << dp[n - 1];
}