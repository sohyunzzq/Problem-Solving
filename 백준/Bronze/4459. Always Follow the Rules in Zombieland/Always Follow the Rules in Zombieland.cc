#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<string> arr(n);
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, arr[i]);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;

		cout << "Rule " << a << ": ";
		if (0 < a && a <= n)
			cout << arr[a - 1];
		else
			cout << "No such rule";
		cout << endl;
	}
}