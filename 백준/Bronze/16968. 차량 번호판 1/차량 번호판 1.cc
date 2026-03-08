#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	int ans = 1;

	ans *= (s[0] == 'c' ? 26 : 10);

	int c = 26;
	int d = 10;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == 'c') {
			if (s[i - 1] == 'c') 
				c = 25;
			ans *= c;
		}
		else {
			if (s[i - 1] == 'd')
				d = (d == 10 ? 9 : 10);
			ans *= d;
		}
		c = 26;
		d = 10;
	}

	cout << ans;
}