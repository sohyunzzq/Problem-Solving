#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int n, m;
vector<int> selected;

void func(int curr) {
	if (curr == m) {
		for (int i = 0; i < selected.size(); i++)
			cout << selected[i] << " ";
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (curr == 0 || selected[curr - 1] <= i) {
			selected.push_back(i);
			func(curr + 1);
			selected.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	func(0);
}