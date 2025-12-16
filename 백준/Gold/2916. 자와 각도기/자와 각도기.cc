#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define endl '\n'

vector<int> angles;
queue<int> q;
bool know[360];

void GetAngle() {
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < angles.size(); i++) {
			int plus = (now + angles[i] + 360) % 360;
			int minus = (now - angles[i] + 360) % 360;

			if (!know[plus]) {
				angles.push_back(plus);
				know[plus] = true;
				q.push(plus);
			}

			if (!know[minus]) {
				angles.push_back(minus);
				know[minus] = true;
				q.push(minus);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		angles.push_back(a);
		know[a] = true;
		q.push(a);
	}

	GetAngle();

	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;

		cout << (know[a] ? "YES" : "NO") << endl;
	}
}