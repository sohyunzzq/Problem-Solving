/*

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'

queue<int> q;
vector<int> visited;
vector<int> arr;

bool CanGo(int num) {
	return 0 <= num && !visited[num];
}

void BFS() {
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now % 3 == 0 && CanGo(now / 3)) {
			visited[now / 3] = true;
			arr[now / 3] = arr[now] + 1;
			q.push(now / 3);
		}

		if (now % 2 == 0 && CanGo(now / 2)) {
			visited[now / 2] = true;
			arr[now / 2] = arr[now] + 1;
			q.push(now / 2);
		}

		if (CanGo(now - 1)) {
			visited[now - 1] = true;
			arr[now - 1] = arr[now] + 1;
			q.push(now - 1);
		}

		if (arr[1]) {
			while (!q.empty())
				q.pop();
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	visited.resize(n + 1);
	arr.resize(n + 1);

	q.push(n);
	visited[n] = true;
	arr[n] = 0;
	BFS();

	cout << arr[1];
}