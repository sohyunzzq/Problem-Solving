#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int n, m;
vector<int> selected;

void func() {
	if (selected.size() == m) {
		for (int i = 0; i < m; i++)
			cout << selected[i] << " ";
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++) {
		selected.push_back(i);
		func();
		selected.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	func();
}