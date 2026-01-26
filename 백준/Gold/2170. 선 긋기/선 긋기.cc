#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Cmp {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
		return a.first < b.first;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> lines(n);
	for (int i = 0; i < n; i++) {
		cin >> lines[i].first >> lines[i].second;
	}

	sort(lines.begin(), lines.end(), Cmp());

	int st = lines[0].first;
	int en = lines[0].second;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (lines[i].first <= en) {
			en = max(en, lines[i].second);
		}
		else {
			ans += en - st;

			st = lines[i].first;
			en = lines[i].second;
		}
	}

	ans += en - st;
	cout << ans;
}