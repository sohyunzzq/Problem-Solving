#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp (pair<int, int> left, pair<int, int> right) {
	if (left.second < right.second)
		return true;
	if (left.second > right.second)
		return false;
	return left.first < right.first;
}

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> arr(n);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a, b };
	}

	sort(arr.begin(), arr.end(), cmp);

	int end_time = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].first >= end_time) {
			cnt++;
			end_time = arr[i].second;
		}
	}
	cout << cnt;
}