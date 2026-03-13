#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	int sum = 0;

	int idx = 0;
	int num = 0;
	while (idx < s.size() && s[idx] != '+' && s[idx] != '-') {
		num *= 10;
		num += int(s[idx++] - '0');
	}
	sum += num;

	while (idx < s.size()) {
		num = 0;
		if (s[idx] == '-') {
			idx++;
			while (idx < s.size() && s[idx] != '-') {
				if (s[idx] == '+') {
					sum -= num;
					num = 0;
					idx++;
				}
				else {
					num *= 10;
					num += int(s[idx++] - '0');
				}
			}
			sum -= num;

		}
		else if (s[idx] == '+') {
			idx++;
			num = 0;
			while (idx < s.size() && s[idx] != '+' && s[idx] != '-') {
				num *= 10;
				num += int(s[idx++] - '0');
			}
			sum += num;
		}

	}

	cout << sum;
}