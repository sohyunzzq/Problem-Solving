/*
[백트래킹]

*/

#include <iostream>
#include <vector>
using namespace std;

#define M_SZ 13
#define endl '\n'

int n, m;
vector<vector<int>> area;
vector<int> choose;
bool path[M_SZ+1];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
int ans;

int GetDist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int City() {
	int sum = 0;
	for (int i = 0; i < home.size(); i++) {
		int temp = home.size() * n * n;
		for (int j = 0; j < choose.size(); j++) {
			temp = min(temp,
				GetDist(home[i].first, home[i].second, chicken[choose[j]].first, chicken[choose[j]].second));
		}
		sum += temp;
	}

	return sum;
}

void func(int index) {
	if (choose.size() == m) {
		// m개 고름
		// 각 home마다 각 m까지의 거리 구하고 다 더해서 갱신
		ans = min(ans, City());
		return;
	}

	for (int i = index; i < chicken.size(); i++) {
		if (!path[i]) {
			choose.push_back(i);
			path[i] = true;
			func(i + 1);
			choose.pop_back();
			path[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	area.resize(n);
	for (int i = 0; i < n; i++) {
		area[i].resize(n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> area[i][j];

			if (area[i][j] == 1)
				home.push_back({ i, j });
			else if (area[i][j] == 2)
				chicken.push_back({ i, j });
		}
	}

	ans = home.size() * n * n;
	func(0);

	cout << ans;
}