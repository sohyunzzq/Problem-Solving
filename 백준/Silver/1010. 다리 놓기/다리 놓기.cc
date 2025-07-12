/*
[DP]
m개 중 n개 고르기, mCn

파스칼의 삼각형
가장자리는 모두 1 (초기화)
DP[i][j] = iCj

좌우대칭이기 때문에 계산은 절반만 하기

*/

#include <iostream>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

#define M_SZ 31

int n, m;
long long DP[M_SZ][M_SZ];

int main() {
	fastio;

	int T;
	cin >> T;

	// 가장자리
	for (int i = 0; i < M_SZ; i++)
		DP[i][0] = DP[i][i] = 1;

	// 나머지 채우기
	for (int i = 2; i < M_SZ; i++)
		for (int j = 1; j <= i / 2; j++)
			DP[i][j] = DP[i][i - j] = DP[i - 1][j - 1] + DP[i - 1][j];

	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> m;

		cout << DP[m][n] << endl;
	}
}