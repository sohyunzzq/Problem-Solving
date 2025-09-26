#include <iostream>
#include <vector>
using namespace std;

#define N_MAX 1'000'000'000

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int left = 0, right = n - 1;
	int l_val = arr[left], r_val = arr[right];
	int min_val = N_MAX * 2 + 5;

	while (left < right) {
		int temp = arr[left] + arr[right];

		// 0 완성
		if (temp == 0) {
			l_val = arr[left];
			r_val = arr[right];
			break;
		}

		// 갱신
		if (abs(temp) < abs(min_val)) {
			min_val = temp;
			l_val = arr[left];
			r_val = arr[right];
		}

		if (temp < 0)
			left++;
		else if (temp > 0)
			right--;
		else {
			left++;
			right--;
		}
	}

	cout << l_val << " " << r_val;
}