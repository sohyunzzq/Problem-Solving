#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define X_SZ 1001

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	pair<int, int> mini = { -1, X_SZ };
	pair<int, int> maxi = { -1, 0 };

	for (int i = 0; i < n; i++) {
		if (nums[i] < mini.second)
			mini = { i, nums[i] };
		if (nums[i] > maxi.second)
			maxi = { i, nums[i] };
	}

	if (mini.first == 0)
		cout << "ez";
	else if (maxi.first == 0)
		cout << "hard";
	else
		cout << "?";
}