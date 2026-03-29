#include <iostream>
using namespace std;

int alpha[26];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	for (int i = 0; i < n; i++) {
		alpha[int(s[i] - 'a')]++;
	}

	int cnt = 0;
	char ans;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] > cnt) {
			cnt = alpha[i];
			ans = char(i + 'a');
		}
	}

	cout << ans << " " << cnt;
}