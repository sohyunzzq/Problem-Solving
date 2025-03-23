/*
정렬하면 무조건 최선일까나..
정렬 O(NlogN) + for문 O(N)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += arr[i] * (n - i);
	}

	cout << ans;
}