/*
[재귀]

DP 배열에 저장해두고,
0과 1이 리턴될 때만 카운트를 세면 되려나

그 카운트를 따로 DP로 저장해야 하나?
피보처럼, 0과 1의 개수를 더해주면 될 듯
*/

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> cnt;

pair<int, int> GetCnt(int num) {
	if (cnt[num].first != 0 && cnt[num].second != 0) {
		return cnt[num];
	}

	if (num == 0) {
		return cnt[num] = { 1, 0 };
	}
	if (num == 1) {
		return cnt[num] = { 0, 1 };
	}

	pair<int, int> MinusOne = GetCnt(num - 1);
	pair<int, int> MinusTwo = GetCnt(num - 2);
	return cnt[num] = { MinusOne.first + MinusTwo.first, MinusOne.second + MinusTwo.second };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int tc = 0; tc < t; tc++) {
		int n;
		cin >> n;

		cnt.resize(n + 1, {0, 0});

		GetCnt(n);

		cout << cnt[n].first << " " << cnt[n].second << '\n';
	}
}