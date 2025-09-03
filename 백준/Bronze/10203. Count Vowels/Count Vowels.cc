#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		int cnt = 0;
		for (int j = 0; s[j]; j++)
			if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
				cnt++;

		cout << "The number of vowels in " << s << " is " << cnt << "." << endl;
	}
}