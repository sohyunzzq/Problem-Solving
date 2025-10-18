#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;

		vector<int> nums(n);
		for (int j = 0; j < n; j++)
			cin >> nums[j];
		
		sort(nums.begin(), nums.end());

		cout << nums[0] << " " << nums[n - 1] << endl;
	}
}