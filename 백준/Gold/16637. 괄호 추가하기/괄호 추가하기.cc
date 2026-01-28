#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
string s;
vector<int> num;
vector<char> oper;
vector<int> choose;
long long ans = -1e12;

void GetAns() {
	// 일회용 애들
	vector<int> num_tmp;
	vector<char> oper_tmp;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			num_tmp.push_back(int(s[i] - '0'));
		else
			oper_tmp.push_back(s[i]);
	}

	// 괄호 먼저 처리
	for (int i = 0; i < n / 2; i++) {
		// oper[i] -> num[i] num[i+1] 계산
		if (choose[i]) {
			switch (oper_tmp[i]) {
			case '+':
				num_tmp[i] += num_tmp[i + 1];
				break;
			case '-':
				num_tmp[i] -= num_tmp[i + 1];
				break;
			case '*':
				num_tmp[i] *= num_tmp[i + 1];
				break;
			case '/':
				num_tmp[i] /= num_tmp[i + 1];
				break;
			}

			num_tmp[i + 1] = 0;
			oper_tmp[i] = '+';
		}
	}

	long long tmp = num_tmp[0];
	for (int i = 0; i < n / 2; i++) {
		switch (oper_tmp[i]) {
		case '+':
			tmp += num_tmp[i + 1];
			break;
		case '-':
			tmp -= num_tmp[i + 1];
			break;
		case '*':
			tmp *= num_tmp[i + 1];
			break;
		case '/':
			tmp /= num_tmp[i + 1];
			break;
		}
	}

	ans = max(ans, tmp);
}

void func(int curr) {
	// curr번째 oper를 괄호 안에 넣을 건지
	if (curr == n / 2) {
		GetAns();
		return;
	}

	for (int i = 0; i <= 1; i++) {
		if (curr != 0 && choose[curr - 1] == 1 && i == 1)
			continue;

		if (choose.size() > 0 && choose[0] == 1)
			return;

		choose.push_back(i);
		func(curr + 1);
		choose.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			num.push_back(int(s[i] - '0'));
		else
			oper.push_back(s[i]);
	}

	func(0);

	cout << ans;
}