#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int alpha[26];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);	
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			alpha[int(s[j] - 'A')] += pow(10, s.size() - j - 1);
		}
	}

	sort(alpha, alpha + 26, greater<>());

	int ans = 0;
	int num = 9;

	for (int i = 0; i < 10; i++) {
		if (!alpha[i])
			break;

		ans += alpha[i] * num;
		num--;
	}

	cout << ans;
}