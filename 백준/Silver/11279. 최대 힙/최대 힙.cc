#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'

priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top() << endl;
				pq.pop();
			}
			else
				cout << 0 << endl;
		}
		else {
			pq.push(x);
		}
	}
}