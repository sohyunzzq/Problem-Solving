#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;

		vector<int> scores(n);
		for (int i = 0; i < n; i++) {
			cin >> scores[i];
		}
		sort(scores.begin(), scores.end());

		int gap = 0;
		for (int i = 0; i < n-1; i++) {
			if (scores[i + 1] - scores[i] > gap)
				gap = scores[i + 1] - scores[i];
		}

		cout << "Class " << tc << endl;
		cout << "Max " << scores[n - 1] << ", Min " << scores[0] << ", Largest gap " << gap << endl;
	}
}