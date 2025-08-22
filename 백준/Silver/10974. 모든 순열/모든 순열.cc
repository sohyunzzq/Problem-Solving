#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

#define SZ 9

int n;
vector<int> selected;
int path[SZ];

void func() {
	if (selected.size() == n) {
		for (int i = 0; i < n; i++)
			cout << selected[i] << " ";
		cout << endl;
	}

	for (int i = 1; i <= n; i++) {
		if (path[i] == 0) {
			path[i] = 1;
			selected.push_back(i);
			func();
			path[i] = 0;
			selected.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	func();
}