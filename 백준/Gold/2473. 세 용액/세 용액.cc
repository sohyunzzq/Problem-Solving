#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	// 투 포인터
	// 처음 원소부터 고정시켜놓고, 나머지 원소들 중에서 두 개 돌리기

	long long total = 3000000000 + 1;
	int ans[3] = {};
	for (int fix = 0; fix < n - 2; fix++) {
		// fix, start, end 모두 겹치면 안 됨
		// 양쪽에서 모이기
		int start = fix + 1;
		int end = n - 1;

		while (start < end) {
			long long tmp = arr[fix] + arr[start] + arr[end];
			if (abs(tmp) < abs(total)) {
				total = tmp;
				ans[0] = arr[fix];
				ans[1] = arr[start];
				ans[2] = arr[end];
			}

			// 합한 값이 0보다 작으면 더 큰 값이 필요함
			if (tmp < 0)
				start++;
			else
				end--;
		}
	}
	
	for (int i = 0; i < 3; i++)
		cout << ans[i] << " ";
}