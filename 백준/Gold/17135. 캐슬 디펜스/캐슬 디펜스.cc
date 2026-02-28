#include <iostream>
#include <vector>
using namespace std;

#define N_SZ 15
#define M_SZ 15

int n, m, d;
vector<vector<int>> origin_map;
vector<vector<int>> copied_map;
vector<pair<int, int>> enemy;
vector<pair<int, int>> copied_enemy;
vector<int> isalive;
vector<int> selected;
int ans = 0;

void Init() {
	copied_map.clear();
	copied_enemy.clear();
	copied_map.resize(n);
	for (int i = 0; i < n; i++)
		copied_map[i].resize(m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			copied_map[i][j] = origin_map[i][j];

	copied_enemy.resize(enemy.size());
	for (int i = 0; i < enemy.size(); i++)
		copied_enemy[i] = enemy[i];

	for (int i = 0; i < isalive.size(); i++)
		isalive[i] = 1;
}

int GetDist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

bool IsOver() {
	for (int i = 0; i < isalive.size(); i++)
		if (isalive[i])
			return false;
	return true;
}

void Simulation() {
	Init();

	int kill_cnt = 0;
	while (1) {
		if (IsOver()) {
			ans = max(ans, kill_cnt);
			break;
		}

		// 궁수 턴
		// 각 궁수가 공격할 적 찾기
		int attacks[3];

		for (int i = 0; i < 3; i++) {
			pair<int, int> archer = { n, selected[i] };

			int min_dist = N_SZ * M_SZ;
			int attack = -1;
			int left = M_SZ;
			for (int j = 0; j < copied_enemy.size(); j++) {
				if (!isalive[j])
					continue;

				int dist = GetDist(archer.first, archer.second, copied_enemy[j].first, copied_enemy[j].second);

				if (dist > d)
					continue;

				if (dist < min_dist) {
					min_dist = dist;
					left = copied_enemy[j].second;
					attack = j;
				}
				else if (dist == min_dist && copied_enemy[j].second < left) {
					left = copied_enemy[j].second;
					attack = j;
				}
			}
			attacks[i] = attack;
		}

		// 공격해서 죽이기
		for (int i = 0; i < 3; i++) {
			if (attacks[i] == -1)
				continue;

			if (isalive[attacks[i]]) {
				isalive[attacks[i]] = 0;
				kill_cnt++;
			}
		}

		// 적 턴
		for (int i = 0; i < isalive.size(); i++) {
			if (isalive[i]) {
				copied_enemy[i].first++;

				if (copied_enemy[i].first == n)
					isalive[i] = 0;
			}
		}
	}
}

void func(int curr) {
	if (selected.size() == 3) {
		Simulation();
		return;
	}

	for (int i = curr; i < m; i++) {
		selected.push_back(i);
		func(i + 1);
		selected.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> d;
	origin_map.resize(n);
	for (int i = 0; i < n; i++)
		origin_map[i].resize(m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> origin_map[i][j];

			if (origin_map[i][j]) {
				enemy.push_back({ i, j });
				isalive.push_back(1);
			}
		}
	}

	// mC3개의 경우의 수를 구하기
	func(0);

	cout << ans;
}