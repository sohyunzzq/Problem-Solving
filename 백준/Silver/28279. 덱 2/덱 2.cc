#include <iostream>
#include <deque>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	deque<int> dq;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int cmd;
		cin >> cmd;

		int x;
		switch (cmd) {
		case 1:
			cin >> x;

			dq.push_front(x);
			break;
		case 2:
			cin >> x;

			dq.push_back(x);
			break;
		case 3:
			if (dq.empty())
				cout << -1;
			else {
				cout << dq.front();
				dq.pop_front();
			}
			cout << endl;
			break;
		case 4:
			if (dq.empty())
				cout << -1;
			else {
				cout << dq.back();
				dq.pop_back();
			}
			cout << endl;
			break;
		case 5:
			cout << dq.size() << endl;
			break;
		case 6:
			cout << dq.empty() << endl;
			break;
		case 7:
			cout << (dq.empty() ? -1 : dq.front()) << endl;
			break;
		case 8:
			cout << (dq.empty() ? -1 : dq.back()) << endl;
			break;
		}
	}
}