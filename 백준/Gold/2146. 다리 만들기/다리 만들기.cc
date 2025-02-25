#include <iostream>
#include <queue>
using namespace std;

#define SZ 100

int n;
int area[SZ][SZ];
int island[SZ][SZ];
int visited[SZ][SZ];
queue<pair<int, int>> q;
int dis[SZ][SZ];
int min_dis = SZ * SZ + 1;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void InitArr(int arr[SZ][SZ]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = 0;
}

int InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y];
}

void Numbering(int num) {
	while (!q.empty()) {
		pair<int, int> v = q.front();
		int x = v.first;
		int y = v.second;
		q.pop();

		island[x][y] = num;

		for (int dr = 0; dr < 4; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			if (CanGo(nx, ny) && area[nx][ny] != 0) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
			}
		}
	}
}

void GetDis(int num) {
	while (!q.empty()) {
		pair<int, int> v = q.front();
		int x = v.first;
		int y = v.second;
		q.pop();

		for (int dr = 0; dr < 4; dr++) {
			int nx = x + dx[dr];
			int ny = y + dy[dr];

			// 내 섬이면 갈 필요 없음
			if (CanGo(nx, ny) && island[nx][ny] != num) {
				// 만약 다른 섬 만났다면?
				// 최단거리 업데이트해주고
				// 큐 비우고 리턴
				if (island[nx][ny] != 0) {
					min_dis = min(min_dis, dis[x][y]);
					while (!q.empty())
						q.pop();
					return;
				}
				visited[nx][ny] = 1;
				q.push({ nx, ny });
				dis[nx][ny] = dis[x][y] + 1;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> area[i][j];

	// BFS를 돌리면서 island 배열에 섬을 넘버링하여 표시
	int num = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (area[i][j] && !visited[i][j]) {
				visited[i][j] = 1;
				q.push({ i, j });
				Numbering(num);
				num++;
			}

	// num번째 섬 한 칸씩 돌면서 거리 재기
	// 다른 섬과 만나면 최단거리이므로 바로 리턴
	InitArr(visited);

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (area[i][j]) {
				InitArr(dis);
				InitArr(visited);
				visited[i][j] = 1;
				q.push({ i, j });
				GetDis(island[i][j]);
			}

	cout << min_dis;
}