#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '_')
			ans++;
	}

	ans *= 5;
	ans += 2 + s.size();

	cout << ans;
}