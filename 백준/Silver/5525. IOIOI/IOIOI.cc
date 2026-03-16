#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	vector<int> cnt;
	for (int i = 0; i < m; i++) {
		if (s[i] == 'I') {
			i++;
			int tmp = 0;
			while (i+1 < m && s[i] == 'O' && s[i+1] == 'I') {
				tmp++;
				i += 2;
			}
			if (tmp)
				cnt.push_back(tmp);
			i--;
		}
	}

	int ans = 0;
	if (n == 1) {
		for (int i = 0; i < cnt.size(); i++)
			ans += cnt[i];
	}
	else {
		for (int i = 0; i < cnt.size(); i++) {
			if (cnt[i] >= n)
				ans += cnt[i] - n + 1;
		}
	}
	cout << ans;
}