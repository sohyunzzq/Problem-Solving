#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'

struct Cmp {
	bool operator()(const int& a, const int& b) {
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

priority_queue<int, vector<int>, Cmp> pq;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (!x) {
			if (pq.empty())
				cout << 0 << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
}