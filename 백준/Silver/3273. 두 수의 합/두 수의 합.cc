#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	int x;
	cin >> x;

	sort(nums.begin(), nums.end());

	int left = 0;
	int right = n - 1;

	int cnt = 0;
	while (left < right) {
		int sum = nums[left] + nums[right];

		if (sum == x) {
			cnt++;
			left++; right--;
		}
		else if (sum < x)
			left++;
		else
			right--;
	}

	cout << cnt;
}