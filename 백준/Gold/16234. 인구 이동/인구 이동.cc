#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int l, r;
vector<vector<int>> population;
vector<vector<int>> temp;
vector<vector<int>> visited;
vector<pair<int, int>> moved;
queue<pair<int, int>> q;
int ans = 0;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void Init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
			population[i][j] = temp[i][j];
		}
	}

}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y];
}

bool IsFinished() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (temp[i][j] != population[i][j])
				return false;
	return true;
}

void Move() {
	int sum = 0;
	for (int i = 0; i < moved.size(); i++)
		sum += population[moved[i].first][moved[i].second];

	int new_num = sum / moved.size();

	for (int i = 0; i < moved.size(); i++) 
		temp[moved[i].first][moved[i].second] = new_num;
}

void BFS() {
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;

		for (int dr = 0; dr < 4; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (CanGo(nx, ny)) {
				int diff = abs(population[x][y] - population[nx][ny]);

				if (l <= diff && diff <= r) {
					visited[nx][ny] = 1;
					q.push({ nx, ny });
					moved.push_back({ nx, ny });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> l >> r;

	population.resize(n);
	temp.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		population[i].resize(n);
		temp[i].resize(n);
		visited[i].resize(n, 0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> population[i][j];
			temp[i][j] = population[i][j];
		}
	}

	while (1) {
		Init();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					q.push({ i, j });
					visited[i][j] = 1;
					BFS();

					if (moved.size() > 0) {
						moved.push_back({ i, j });
						Move();

						moved.clear();
					}
				}
			}
		}

		if (IsFinished())
			break;
		ans++;
	}

	cout << ans;
}