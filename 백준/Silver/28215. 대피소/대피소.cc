#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_XY 100'000

int n, k;
vector<pair<int, int>> homes;
vector<int> selected;
vector<int> check;
int ans = MAX_XY * 2 + 1;

void GetDist() {
	vector<int> min_dists;

	for (int i = 0; i < n; i++) {
		if (check[i])
			continue;

		pair<int, int> home = homes[i];
		vector<int> dists;
		for (int j = 0; j < k; j++) {
			pair<int, int> emer = homes[selected[j]];

			int tmp_dist = abs(home.first - emer.first) + abs(home.second - emer.second);
			dists.push_back(tmp_dist);
		}

		int tmp_min = MAX_XY * 2 + 1;
		for (int i = 0; i < k; i++)
			tmp_min = min(tmp_min, dists[i]);
		min_dists.push_back(tmp_min);
	}

	sort(min_dists.begin(), min_dists.end(), greater<>());

	ans = min(ans, min_dists[0]);
}

void func(int curr) {
	// curr번째 집을 대피소로 할 것인지
	if (selected.size() == k) {
		GetDist();
		return;
	}

	for (int i = curr; i < n; i++) {
		check[i] = 1;
		selected.push_back(i);
		func(i + 1);
		check[i] = 0;
		selected.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	check.resize(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		homes.push_back({ x, y });
	}

	if (n != k)
		func(0);
	else
		ans = 0;

	cout << ans;
}