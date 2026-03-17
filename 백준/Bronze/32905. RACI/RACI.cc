#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;

	bool flag = true;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;

			if (c == 'A')
				cnt++;
		}

		if (cnt != 1)
			flag = false;
	}

	cout << (flag ? "Yes" : "No");
}