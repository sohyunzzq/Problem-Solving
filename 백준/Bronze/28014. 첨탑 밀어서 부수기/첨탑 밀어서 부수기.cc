#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> height;
	height.resize(n);

	for (int i = 0; i < n; i++)
		cin >> height[i];

	int cnt = 1;
	
	for (int i = 1; i < n; i++) {
		int now = height[i];

		if (height[i - 1] <= now)
			cnt++;
	}

	cout << cnt;
}