#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

#define MAX_N 1'000'000

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	bool IsPrime[MAX_N + 1];
	for (int i = 1; i <= MAX_N; i++)
		IsPrime[i] = true;

	IsPrime[0] = IsPrime[1] = false;

	for (int i = 2; i * i <= MAX_N; i++) {
		if (!IsPrime[i])
			continue;

		for (int j = 2; i * j <= MAX_N; j++)
			IsPrime[i * j] = false;
	}

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;

		int cnt = 0;
		for (int i = 2; i <= n / 2; i++)
			if (IsPrime[i] && IsPrime[n - i])
				cnt++;

		cout << cnt << endl;
	}
}