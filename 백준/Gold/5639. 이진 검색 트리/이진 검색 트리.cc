#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<int> nodes;

void post(int start, int end) {
	if (start == end) {
		cout << nodes[start] << endl;
		return;
	}

	int root = nodes[start];

	int p = -1;
	for (int i = start; i <= end; i++) {
		if (nodes[i] > root) {
			p = i - 1;
			break;
		}
	}

	if (p == -1 || nodes[p] == root) {
		post(start + 1, end);
	}
	else if (p > 0) {
		post(start + 1, p);
		post(p + 1, end);
	}
	cout << root << endl;
}

int main() {
	fastio;

	int n;
	while (cin >> n) {
		nodes.push_back(n);
	}

	post(0, nodes.size() - 1);
}