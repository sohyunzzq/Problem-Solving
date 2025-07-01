#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, s;
	cin >> n >> s;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	
	int sum = nums[0];
	int left = 0;
	int right = 0;
	int diff = n + 1;

	while (right < n && left <= right) {
		if (sum >= s) {
			diff = min(diff, right - left + 1);
			sum -= nums[left];
			left++;
		}
		else {
			right++;
			if (right >= n)
				break;
			sum += nums[right];
		}
	}

	cout << (diff == n + 1 ? 0 : diff);
}