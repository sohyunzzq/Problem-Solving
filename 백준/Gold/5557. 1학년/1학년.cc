/*
0 <= (현재까지의 연산 결과) <= 20
이거 만족 안 하면 바로 빠꾸쳐야 됨

뒤를 중복 계산할 수 있으므로 dp를 만들어서 누적
*/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100
#define MIN_VAL 0
#define MAX_VAL 20

int n;
vector<int> arr;
long long DP[MAX_N][MAX_VAL - MIN_VAL + 1];

long long func(int curr, long long sum) {
	if (sum > MAX_VAL || sum < MIN_VAL)
		return 0;

	if (curr == n - 1)
		return (sum == arr[n - 1]);

	// 이미 계산함
	if (DP[curr][sum] != -1)
		return DP[curr][sum];

	DP[curr][sum] = 0;

	// +
	DP[curr][sum] += func(curr + 1, sum + arr[curr]);
	// -
	DP[curr][sum] += func(curr + 1, sum - arr[curr]);

	return DP[curr][sum];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	arr.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MAX_VAL - MIN_VAL + 1; j++) {
			DP[i][j] = -1;
		}
	}

	DP[n - 2][arr[n - 1]] = func(1, arr[0]);

	cout << DP[n - 2][arr[n - 1]];
}