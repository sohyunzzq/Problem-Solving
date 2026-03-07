#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> ans;

void func(long long x) {
	ans.push_back(x);

	if (x % 10 == 0)
		return;

	for (int i = 0; i <= x % 10 - 1; i++)
		func(x * 10 + i);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i <= 9; i++)
		func(i);

	sort(ans.begin(), ans.end());

	cout << (n >= ans.size() ? -1 : ans[n]);
}