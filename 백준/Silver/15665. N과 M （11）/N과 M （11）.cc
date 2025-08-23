#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

#define SZ 10001

int n, m;
vector<int> nums;
bool path[SZ];
vector<int> selected;

void func() {
	if (selected.size() == m) {
		for (int i = 0; i < m; i++)
			cout << selected[i] << " ";
		cout << endl;
		return;
	}

	for (int i = 0; i < nums.size(); i++) {
		selected.push_back(nums[i]);
		func();
		selected.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (!path[num]) {
			path[num] = true;
			nums.push_back(num);
		}
	}
	sort(nums.begin(), nums.end());
	func();
}