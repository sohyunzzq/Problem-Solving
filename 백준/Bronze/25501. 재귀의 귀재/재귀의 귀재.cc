#include <iostream>
using namespace std;
#define endl '\n'

int Palindrome(string s) {
	int left = 0;
	int right = s.size() - 1;

	while (left < right) {
		if (s[left] != s[right]) {
			cout << 0 << " ";
			return left + 1;
		}
		left++; right--;
	}
	
	if (left >= right)
		cout << 1 << " ";
	return left + 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		string s;
		cin >> s;

		int num = Palindrome(s);
		cout << num << endl;
	}
}