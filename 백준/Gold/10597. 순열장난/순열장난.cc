#include <iostream>
#include <vector>
using namespace std;

#define SZ 51

string s;
int len;
int N = 9;
bool check[SZ];
vector<int> ans;
bool flag = false;

void func(int idx) {
	if (idx >= len) {
		if (!flag) {
			for (int i = 0; i < N; i++)
				cout << ans[i] << " ";
			flag = true;
		}
		return;
	}

	// 한 자리
	int num1 = int(s[idx] - '0');
	// 넣기
	if (num1 <= N && !check[num1]) {
		ans.push_back(num1);
		check[num1] = true;

		func(idx + 1);

		ans.pop_back();
		check[num1] = false;
	}

	// 두 자리
	if (idx + 1 < len) {
		int num2 = num1 * 10 + int(s[idx + 1] - '0');

		// 넣기
		if (num2 <= N && !check[num2]) {
			ans.push_back(num2);
			check[num2] = true;

			func(idx + 2);

			ans.pop_back();
			check[num2] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> s;

	len = s.size();

	// 1부터 N까지의 수열
	if (len <= 9)
		for (int i = 0; i < len; i++)
			cout << s[i] << " ";
	else {
		for (int i = 10; i < len; i += 2)
			N++;

		func(0);
	}
}