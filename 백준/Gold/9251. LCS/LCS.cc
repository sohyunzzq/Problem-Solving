#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string A, B;
	cin >> A >> B;

	int A_len = A.size();
	int B_len = B.size();

	vector<vector<int>> DP;
	DP.resize(A_len);
	for (int i = 0; i < A_len; i++)
		DP[i].resize(B_len);

	DP[0][0] = (A[0] == B[0]);
	
	// 0행
	for (int i = 1; i < B_len; i++) {
		if (A[0] == B[i])
			DP[0][i] = 1;
		else
			DP[0][i] = DP[0][i - 1];
	}

	// 0열
	for (int i = 1; i < A_len; i++) {
		if (A[i] == B[0])
			DP[i][0] = 1;
		else
			DP[i][0] = DP[i - 1][0];
	}

	for (int i = 1; i < A_len; i++) {
		for (int j = 1; j < B_len; j++) {
			if (A[i] == B[j])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else 
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	cout << DP[A_len - 1][B_len - 1];
}