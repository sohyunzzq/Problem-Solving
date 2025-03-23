/*

*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, int> names;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		names[str]++;
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;

		names[str]++;
	}

	vector<string> ans;
	for (auto it : names) {
		if (it.second >= 2) {
			ans.push_back(it.first);
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}