/*
6이랑 9는 같이 쓸 수 있음

66: 1
69: 1
99: 1
669: 2
666666: 3
666666999999: 6
*/

#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	int arr[10] = {};
	for (int i = 0; s[i]; i++)
		arr[s[i] - '0']++;

	arr[6] += arr[9];
	arr[6] = (arr[6] + 1) / 2;

	int ans = 0;
	for (int i = 0; i < 9; i++) {
		ans = max(ans, arr[i]);
	}

	cout << ans;
}