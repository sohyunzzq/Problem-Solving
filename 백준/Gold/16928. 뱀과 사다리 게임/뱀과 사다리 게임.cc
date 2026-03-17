#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 100

int arr[MAX_N+1];
int visited[MAX_N + 1];
queue<int> q;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		arr[x] = y;
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		arr[x] = y;
	}

	q.push(1);
	while (!q.empty()) {
		int x = q.front(); q.pop();

		for (int i = 1; i <= 6; i++) {
			int nx = x + i;
			
			if (nx == 100) {
				visited[nx] = visited[x] + 1;
				while (!q.empty())
					q.pop();
				break;
			}

			if (nx > 100)
				break;

			if (visited[nx])
				continue;

			if (arr[nx] == 0) {
				q.push(nx);
				visited[nx] = visited[x] + 1;
			}
			else {
				if (visited[arr[nx]] && visited[arr[nx]] < visited[x]+1)
					continue;

				q.push(arr[nx]);
				visited[arr[nx]] = visited[nx] = visited[x] + 1;
			}
		}
	}

	cout << visited[100];
}