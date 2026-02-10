#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	deque<int> dq;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "push_front") {
			int x;
			cin >> x;

			dq.push_front(x);
		}
		else if (s == "push_back") {
			int x;
			cin >> x;

			dq.push_back(x);
		}
		else if (s == "pop_front") {
			if (dq.empty())
				cout << -1 << endl;
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (dq.empty())
				cout << -1 << endl;
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (s == "size") {
			cout << dq.size() << endl;
		}
		else if (s == "empty") {
			cout << dq.empty() << endl;
		}
		else if (s == "front") {
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.front() << endl;
		}
		else if (s == "back") {
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.back() << endl;
		}
	}
}