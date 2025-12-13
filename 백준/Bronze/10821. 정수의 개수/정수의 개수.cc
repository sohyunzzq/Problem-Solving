#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	int cnt = 0;
	int idx = 0;
	while (s[idx]) {
		if (s[idx++] == ',')
			cnt++;
	}
	cout << cnt + 1;
}