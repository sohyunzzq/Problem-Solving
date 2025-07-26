#include <iostream>
#include <string>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(0);

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		int a = int(s[s.size() - 1] - '0');
		if (a % 2 == 0)
			cout << "even";
		else
			cout << "odd";
		cout << endl;
	}
}