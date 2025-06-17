/*
[BFS]

일차원 배열 BFS
*/

#include <iostream>
#include <queue>
using namespace std;

#define N_SZ 100000+1

int n, k;
int visited[N_SZ] = {};
queue<int> q;

bool InRange(int x) {
	return 0 <= x && x < N_SZ;
}

bool CanGo(int x) {
	return InRange(x) && !visited[x];
}

void BFS() {
	while (!q.empty()) {
		int x = q.front(); q.pop();

		// 동생 위치
		if (x == k)
			return;

		if (CanGo(x + 1)) {
			q.push(x + 1);
			visited[x + 1] = visited[x] + 1;
		}
		if (CanGo(x - 1)) {
			q.push(x - 1);
			visited[x - 1] = visited[x] + 1;
		}
		if (CanGo(2 * x)) {
			q.push(2 * x);
			visited[2 * x] = visited[x] + 1;
		}
	}
}

int main() {
	cin >> n >> k;
	q.push(n);
	visited[n] = 1;
	BFS();

	cout << visited[k] - 1;
}