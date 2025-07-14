#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

#define mod 1000000007

vector<long long> DP;

int main() {
	fastio;

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int c, v, l;
		cin >> c >> v >> l;

		DP.clear();
		DP.resize(l + 1);

		DP[1] = v;
		DP[2] = v * v + c * v;

		for (int i = 3; i <= l; i++)
			DP[i] = (v * DP[i - 1] + v * c * DP[i - 2]) % mod;
		
		cout << "Case #" << tc << ": " << DP[l] << endl;
	}
}