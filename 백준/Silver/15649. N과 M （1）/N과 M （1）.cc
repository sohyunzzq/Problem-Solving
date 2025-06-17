#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define N_SZ 8

int n, m;
vector<int> num;
int path[N_SZ + 1];

void func(int curr) {
	if (curr == m) {
		for (int i = 0; i < m; i++) {
			cout << num[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (path[i] == 0) {
			num.push_back(i);
			path[i] = 1;

			func(curr + 1);
			
			num.pop_back();
			path[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	func(0);
}