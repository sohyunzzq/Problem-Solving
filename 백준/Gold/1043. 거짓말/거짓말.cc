#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> uf;

int Find(int x) {
	if (uf[x] == x)
		return x;
	return uf[x] = Find(uf[x]);
}

void Union(int x, int y) {
	int X = Find(x);
	int Y = Find(y);

	uf[X] = Y;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	uf.resize(n + 1);

	for (int i = 0; i <= n; i++)
		uf[i] = i;

	int cnt;
	cin >> cnt;

	vector<int> know(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> know[i];
	}
	for (int i = 1; i < cnt; i++) {
		Union(know[i - 1], know[i]);
	}

	vector<vector<int>> party(m);
	for (int i = 0; i < m; i++) {
		cin >> cnt;
		party[i].resize(cnt);

		for (int j = 0; j < cnt; j++)
			cin >> party[i][j];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 1; j < party[i].size(); j++)
			Union(party[i][j - 1], party[i][j]);
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (know.size() == 0) {
			ans = m;
			break;
		}
		if (Find(know[0]) != Find(party[i][0]))
			ans++;
	}
	cout << ans;
}