#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int n, m;
vector<int> nums;
vector<int> selected;
vector<int> path;

void func() {
	if (selected.size() == m) {
		for (int i = 0; i < m; i++)
			cout << selected[i] << " ";
		cout << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (selected.size() == 0 || !path[i]) {
			selected.push_back(nums[i]);
			path[i] = 1;
			func();
			selected.pop_back();
			path[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	nums.resize(n);
	path.resize(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	sort(nums.begin(), nums.end());
	func();
}