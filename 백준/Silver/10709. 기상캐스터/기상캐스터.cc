#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

vector<vector<char>> cloud;
vector<vector<int>> ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int h, w;
	cin >> h >> w;

	cloud.resize(h);
	ans.resize(h);
	for (int i = 0; i < h; i++) {
		cloud[i].resize(w);
		ans[i].resize(w, -1);
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> cloud[i][j];
			
			if (cloud[i][j] == 'c')
				ans[i][j] = 0;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w - 1; j++) {
			if (ans[i][j] >= 0 && ans[i][j+1] != 0) {
				ans[i][j + 1] = ans[i][j] + 1;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}