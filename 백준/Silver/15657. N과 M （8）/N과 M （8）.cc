#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int n, m;
vector<int> nums;
vector<int> selected;

void func(int curr) {
	if (selected.size() == m) {
		for (int i = 0; i < m; i++)
			cout << selected[i] << " ";
		cout << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (selected.size() == 0 || nums[i] >= selected[curr - 1]) {
			selected.push_back(nums[i]);
			func(curr + 1);
			selected.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	nums.resize(n);

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	sort(nums.begin(), nums.end());

	func(0);
}