#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
	fastio;

	int n;
	string s;
	cin >> n >> s;

	int ans = 0;
	int tmp = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == 'a' && s[i - 1] == 'h')
			tmp++;
		else if (s[i] == 'h' && s[i - 1] == 'a')
			tmp++;
		else {
			ans = max(ans, tmp);
			tmp = 1;
		}
	}
	ans = max(ans, tmp);

	if (n == 1)
		if (s[0] != 'a' && s[0] != 'h')
			ans = 0;
	cout << ans;
}