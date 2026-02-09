#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	while (1) {
		int n;
		int arr[100];
		int cnt;

		for (int i = 0; i < 100; i++)
			arr[i] = 0;
		while (1) {
			cin >> n;

			if (n == -1)
				break;
			if (n == 0) {
				cnt = 0;
				for (int i = 1; i < 50; i++) {
					if (arr[i] && arr[i * 2])
						cnt++;
				}
				cout << cnt << endl;
				for (int i = 0; i < 100; i++)
					arr[i] = 0;
			}
			else {
				arr[n]++;
			}
		}
		if (n == -1)
			break;
	}
}