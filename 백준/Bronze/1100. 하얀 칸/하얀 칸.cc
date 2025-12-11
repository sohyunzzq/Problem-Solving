#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string area[8];
	for (int i = 0; i < 8; i++)
		cin >> area[i];

	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 0 && area[i][j] == 'F')
					cnt++;
			}
		}
		else {
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 1 && area[i][j] == 'F')
					cnt++;
			}
		}
	}
	cout << cnt;
}