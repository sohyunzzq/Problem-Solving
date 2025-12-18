#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	// 일차항이 있는지 먼저 확인
	bool x_flag = false;

	int idx = 0;
	int a_end = 0;
	while (idx < s.size()) {
		if (s[idx] == 'x') {
			x_flag = true;
			a_end = idx;
			break;
		}
		idx++;
	}

	if (s == "0")
		cout << "W";
	// 일차항 존재
	else if (x_flag) {
		// 처음이 음수인가?
		int a_start = 0;
		if (s[0] == '-') {
			cout << "-";
			a_start++;
		}

		// a 구하기
		int a = 0;
		for (int i = a_start; i < a_end; i++) {
			a = a * 10 + int(s[i] - '0');
		}

		if (a / 2 == -1)
			cout << "-xx";
		else if (a / 2 == 1)
			cout << "xx";
		else
			cout << a / 2 << "xx";

		// 상수항
		int b = 0;
		int b_start = a_end + 2;

		if (b_start < s.size() && s[b_start] != '0')
			cout << s[b_start - 1];
		for (int i = b_start; i < s.size(); i++) {
			b = b * 10 + int(s[i] - '0');
		}

		if (b == 0)
			cout << "+W";
		else if (b == 1)
			cout << "x+W";
		else
			cout << b << "x+W";
	}
	// 상수항만 존재
	else {
		if (s == "-1")
			cout << "-x+W";
		else if (s == "1")
			cout << "x+W";
		else
			cout << s << "x+W";
	}
}