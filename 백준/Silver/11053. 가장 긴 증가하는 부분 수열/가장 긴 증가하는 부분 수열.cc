#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> LIS;
	LIS.push_back(arr[0]);

	for (int i = 1; i < n; i++) {
		if (arr[i] > LIS[LIS.size() - 1])
			LIS.push_back(arr[i]);
		else
			LIS[lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin()] = arr[i];
	}

	cout << LIS.size();
}