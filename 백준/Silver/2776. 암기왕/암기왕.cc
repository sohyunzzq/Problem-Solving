#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;
	vector<int> note;

	for (int tc = 1; tc <= T; tc++) {
		note.clear();

		int n, m;
		cin >> n;
		note.resize(n);
		for (int i = 0; i < n; i++)
			cin >> note[i];
		sort(note.begin(), note.end());
		cin >> m;

		for (int i = 0; i < m; i++) {
			int num;
			cin >> num;

			int left = 0, right = n - 1;
			int mid;
			while (left <= right) {
				mid = (left + right) / 2;

				if (note[mid] > num)
					right = mid - 1;
				else if (note[mid] < num)
					left = mid + 1;
				else
					break;
			}

			if (note[mid] == num)
				cout << 1;
			else
				cout << 0;
			cout << endl;
		}
	}
}