#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	queue<int> q;

	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int num;
			cin >> num;

			q.push(num);
		}
		else if (cmd == "pop") {
			if (!q.empty()) {
				cout << q.front();
				q.pop();
			}
			else
				cout << -1;
			cout << endl;
		}
		else if (cmd == "size")
			cout << q.size() << endl;
		else if (cmd == "empty")
			cout << (q.empty()) << endl;
		else if (cmd == "front") {
			if (!q.empty())
				cout << q.front();
			else
				cout << -1;
			cout << endl;
		}
		else if (cmd == "back") {
			if (!q.empty())
				cout << q.back();
			else
				cout << -1;
			cout << endl;
		}
	}
}