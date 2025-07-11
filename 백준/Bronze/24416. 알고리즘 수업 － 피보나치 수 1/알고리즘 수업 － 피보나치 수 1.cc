#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);

#define N_SZ 40

long long ans[N_SZ];

int main() {
	int n;
	cin >> n;

	ans[1] = 1;

	for (int i = 2; i <= n; i++)
		ans[i] = ans[i - 1] + ans[i - 2];
	
	cout << ans[n] << " " << n - 2;
}