/*
[BFS]

1인 데를 찾고 BFS 돌리면서 0인 데를 1로 만들기
현재 area를 그대로 복사하고, 그 복사본에서 1로 만든 후 다 끝나면 area에 붙여쓰기

앞으로 진행 가능한지 검사하려면 area와 BFS가 끝난 후 temp가 같은지 검사?
만약 area와 temp가 똑같고, 전부 1이면 다 익은 거
						  1이 아닌 게 있으면 불가능한 거

아니지
1일 때 한 번만 넣고 0일 때 계속 +1 하면서 걍 최단거리 찾으면 되는 거 아냐?

아니지
1인 게 여러 개일 수 있음 -> 동시에 뻗어나감
그니까 1인 걸 그때그때 넣는 게 맞음...
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int ans = 0;
vector<vector<int>> area;
vector<vector<int>> temp;
vector<vector<int>> dist;
vector<vector<int>> visited;
queue<pair<int, int>> q;

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && area[x][y] == 0 && !visited[x][y];
}

void CopyArr(vector<vector<int>> *dst, vector<vector<int>> *src) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			(*dst)[i][j] = (*src)[i][j];
}

void InitArr(vector<vector<int>> *arr) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			(*arr)[i][j] = 0;
}

void BFS() {
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, 1, 0, -1 };
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;

		for (int dr = 0; dr < 4; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (CanGo(nx, ny)) {
				area[nx][ny] = 1;
				visited[nx][ny] = 1;
				q.push({ nx, ny });
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main() {
	cin >> m >> n;
	area.resize(n);
	visited.resize(n);
	temp.resize(n);
	dist.resize(n);
	for (int i = 0; i < n; i++) {
		area[i].resize(m);
		visited[i].resize(m, 0);
		dist[i].resize(m, 0);
		temp[i].resize(m, -2);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> area[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (area[i][j] == 1 && !visited[i][j]) {
				visited[i][j] = 1;
				dist[i][j] = 1;
				q.push({ i, j });
			}
		}
	}

	BFS();

	bool IsCompleted = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (area[i][j] == 0) {
				IsCompleted = false;
				break;
			}
			ans = max(dist[i][j], ans);
		}
	}

	cout << (IsCompleted ? ans - 1 : -1);
}