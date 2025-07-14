#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<int> DP;

int main() {
	fastio;

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int c, d;
		cin >> c >> d;

		string s;
		cin >> s;

		DP.clear();
		DP.resize(c, c + 1);

		DP[0] = 0;
		for (int i = 1; i < c; i++) {
			if (s[i] == '.') {
				bool flag = false;
				for (int j = max(0, i - d - 1); j < i; j++) {
					if (DP[j] != 'X') {
						DP[i] = min(DP[i], DP[j]);
						flag = true;
					}
				}
				if (flag)
					DP[i]++;
			}
		}

		cout << "Day #" << tc << endl;
		cout << c << " " << d << endl;
		cout << s << endl;
		if (DP[c - 1] > c)
			cout << 0;
		else
			cout << DP[c - 1];
		cout << endl << endl;
	}
}