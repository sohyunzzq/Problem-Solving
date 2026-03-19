#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define endl '\n'

#define MAX_N 10000

int a, b;
bool visited[MAX_N];
queue<pair<int, string>> q;
vector<char> ans;

void Init() {
	for (int i = 0; i < MAX_N; i++)
		visited[i] = false;
	while (!q.empty())
		q.pop();
	ans.clear();
}

void BFS() {
	while (!q.empty()) {
		int x = q.front().first;
		string cmd = q.front().second; q.pop();
		int nx;

		// D
		nx = 2 * x % MAX_N;
		if (!visited[nx]) {
			if (nx == b) {
				cout << cmd + "D";
				break;
			}
			q.push({ nx, cmd + "D" });
			visited[nx] = true;
		}

		// S
		nx = (x + 9999) % MAX_N;
		if (!visited[nx]) {
			if (nx == b) {
				cout << cmd + "S";
				break;
			}
			q.push({ nx, cmd + "S" });
			visited[nx] = true;
		}

		// L
		nx = (x * 10 + x / 1000) % MAX_N;
		if (!visited[nx]) {
			if (nx == b) {
				cout << cmd + "L";
				break;
			}
			q.push({ nx, cmd + "L" });
			visited[nx] = true;
		}

		// R
		nx = (x / 10) + (x % 10) * 1000;
		if (!visited[nx]) {
			if (nx == b) {
				cout << cmd + "R";
				break;
			}
			q.push({ nx, cmd + "R" });
			visited[nx] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Init();

		cin >> a >> b;

		q.push({ a, "" });
		BFS();

		cout << endl;
	}
}