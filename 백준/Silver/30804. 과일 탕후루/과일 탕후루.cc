#include <iostream>
#include <vector>
using namespace std;

#define MAX_FRUIT 9

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	int cnt[MAX_FRUIT];
	for (int i = 1; i <= MAX_FRUIT; i++)
		cnt[i] = 0;

	int ans = 0;

	int kinds = 0;
	int left = 0;
	for (int right = 0; right < n; right++) {
		cnt[arr[right]]++;
		if (cnt[arr[right]] == 1)
			kinds++;

		while (kinds > 2) {
			cnt[arr[left]]--;
			if (cnt[arr[left]] == 0)
				kinds--;
			left++;
		}

		ans = max(ans, right - left + 1);
	}

	cout << ans;
}