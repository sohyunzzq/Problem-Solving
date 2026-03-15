#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<int> cmd(n);
	for (int i = 0; i < n; i++)
		cin >> cmd[i];

	deque<int> dq;
	for (int i = n - 1; i >= 0; i--) {
		switch (cmd[i]) {
		case 1: {
			dq.push_back(n - i);
			break;
		}
		case 2: {
			int tmp = dq.back();
			dq.pop_back();
			dq.push_back(n - i);
			dq.push_back(tmp);
			break;
		}
		case 3:
			dq.push_front(n - i);
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		cout << dq.back() << " ";
		dq.pop_back();
	}
}