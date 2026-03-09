#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, l;
	cin >> n >> l;

	vector<int> apples(n);
	for (int i = 0; i < n; i++)
		cin >> apples[i];

	sort(apples.begin(), apples.end());

	for (int i = 0; i < n; i++) {
		if (apples[i] > l)
			break;
		l++;
	}

	cout << l;
}