#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> nums;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		nums.push_back(num);
	}
	
	sort(nums.begin(), nums.end());
	
	int left = 0;
	int right = 0;

	int ans = 2'000'000'001;
	while (right < n && left <= right) {
		int diff = nums[right] - nums[left];

		if (diff < m)
			right++;
		else {
			ans = min(ans, diff);
			left++;
		}
	}

	cout << ans;
}