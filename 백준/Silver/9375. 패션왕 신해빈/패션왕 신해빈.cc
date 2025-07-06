#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n;
vector<pair<string, int>> category;
int ans;

int main() {
	fastio;

	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {
		category.clear();

		cin >> n;

		for (int i = 0; i < n; i++) {
			string name, cate;
			cin >> name >> cate;

			bool flag = false;
			for (int j = 0; j < category.size(); j++) {
				if (cate == category[j].first) {
					category[j].second++;
					flag = true;
					break;
				}
			}
			if (!flag)
				category.push_back({ cate, 1 });
		}

		ans = 1;
		for (int i = 0; i < category.size(); i++)
			ans *= (category[i].second + 1);

		cout << ans - 1 << endl;
	}
}