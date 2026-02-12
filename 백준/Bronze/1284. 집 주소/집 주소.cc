#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int arr[10] = { 4, 2 };
	for (int i = 2; i < 10; i++)
		arr[i] = 3;

	string s;
	while (1) {
		cin >> s;

		if (s == "0")
			break;

		int cnt = 1;
		for (int i = 0; i < s.size(); i++)
			cnt += arr[int(s[i] - '0')] + 1;

		cout << cnt << endl;
	}
}