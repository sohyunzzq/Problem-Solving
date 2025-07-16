#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	long long left = 0;
	while (s[left] == '0')
		left++;

	long long right = s.size() - 1;
	while (s[right] == '0')
		right--;

	long long cnt = 0;
	for (int i = left; i < right; i++)
		if (s[i] == '0')
			cnt++;

	cout << cnt;
}