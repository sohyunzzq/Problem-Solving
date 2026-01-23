#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	int len1 = s1.size();
	int len2 = s2.size();

	vector<vector<int>> DP;
	DP.resize(len1);
	for (int i = 0; i < len1; i++)
		DP[i].resize(len2);

	DP[0][0] = (s1[0] == s2[0]);
	
	// 0행
	for (int i = 1; i < len2; i++) {
		DP[0][i] = DP[0][i - 1];
		if (!DP[0][i] && s1[0] == s2[i])
			DP[0][i] = 1;
	}

	// 0열
	for (int i = 1; i < len1; i++) {
		DP[i][0] = DP[i-1][0];
		if (!DP[i][0] && s1[i] == s2[0])
			DP[i][0] = 1;
	}

	for (int i = 1; i < len1; i++) {
		for (int j = 1; j < len2; j++) {
			if (s1[i] == s2[j]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}

	cout << DP[len1 - 1][len2 - 1];
}