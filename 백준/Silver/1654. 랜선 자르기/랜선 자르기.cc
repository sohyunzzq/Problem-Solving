/*
[이분탐색]

태그 안 깠으면 못 풀었을 듯

제일 큰 길이를 잡고 이분탐색
셌는데 n개 이상이면 left를 업데이트 (찾아볼 길이 늘이기)
n개 미만이면 right를 업데이트 (찾아볼 길이 줄이기)
*/

#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<long long> arr;

long long GetCnt(int len) {
	long long cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += arr[i] / len;
	}
	return cnt;
}

int main() {
	cin >> k >> n;
	arr.resize(k);

	long long left = 1, right = 0;

	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		right = max(right, arr[i]);
	}

	long long ans = 0;
	while (left <= right) {
		long long middle = (left + right) / 2;
		long long cnt = GetCnt(middle);

		if (cnt < n)
			right = middle - 1;
		else {
			left = middle + 1;
			ans = max(ans, middle);
		}
	}

	cout << ans;
}