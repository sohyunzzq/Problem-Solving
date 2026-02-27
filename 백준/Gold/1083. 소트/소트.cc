#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int s;
	cin >> s;

	for (int i = 0; i < n; i++) {
		if (!s)
			break;

		int max_val = arr[i];
		int idx;
		// 범위 내에 나보다 큰 애가 있는지 확인
		for (int j = 1; j <= s; j++) {
			// 인덱스 범위 초과
			if (i + j >= n)
				break;

			if (arr[i + j] > max_val) {
				max_val = arr[i + j];
				idx = i + j;
			}
		}

		// 내가 제일 큼 -> 지금이 최선
		if (max_val == arr[i])
			continue;

		// i번째와 idx 버블소트
		for (int j = 0; j < idx - i; j++) {
			int tmp = arr[idx - j];
			arr[idx - j] = arr[idx - j - 1];
			arr[idx - j - 1] = tmp;
			s--;
		}
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}