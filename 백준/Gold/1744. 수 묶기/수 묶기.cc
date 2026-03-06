#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	int ans = 0;

	int minus = -1;
	int zero = -1;
	int plus = -1;

	int idx = 0;
	while (idx < n) {
		if (arr[idx] < 0)
			minus = idx;
		else if (arr[idx] == 0)
			zero = idx;
		else
			plus = idx;
		idx++;
	}

	// 양수 있음 -> 몇 개?
	if (plus >= 0) {
		if (zero >= 0)
			plus -= zero;
		else
			plus -= minus;
	}

	// 음수 있음 -> 몇 개?
	if (minus >= 0)
		minus++;

	// 음수 계산
	if (minus >= 0) {
		// 짝수 개 -> 다 곱해서 더해
		if (minus % 2 == 0)
			for (int i = 0; i < minus; i += 2)
				ans += arr[i] * arr[i + 1];

		// 홀수 개 -> 하나 빼고 다 곱해서 더해
		else {
			for (int i = 0; i < minus - 1; i += 2)
				ans += arr[i] * arr[i + 1];

			// 0이 없으면 나머지도 더해야 함
			if (zero == -1)
				ans += arr[minus - 1];
		}
	}
	
	// 양수 시작 인덱스
	int st = 0;
	if (plus >= 0) {
		while (st < n && arr[st++] <= 0)
			;
		st--;

		// 1은 더하는 게 이득
		while (st < n && arr[st] == 1) {
			ans++;
			st++;
			plus--;
		}
	}

	// 양수 계산
	if (plus >= 0) {
		// 짝수 개 -> 다 곱해서 더해
		if (plus % 2 == 0)
			for (int i = 0; i < plus; i += 2)
				ans += arr[st + i] * arr[st + i + 1];

		// 홀수 개 -> 하나 빼고 다 곱해서 더해
		else {
			ans += arr[st];
			for (int i = 1; i < plus; i += 2)
				ans += arr[st + i] * arr[st + i + 1];
		}
	}

	cout << ans;
}