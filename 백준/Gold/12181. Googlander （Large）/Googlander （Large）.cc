#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int r, c;
		cin >> r >> c;

		long long DP[25+1][25+1] = {};
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				if (i == 1 || j == 1)
					DP[i][j] = 1;
				else
					DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
		

		cout << "Case #" << tc << ": " << DP[r][c] << endl;
	}
}