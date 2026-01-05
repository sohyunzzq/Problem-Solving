#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;

		int p1 = 0, p2 = 0;

		for (int i = 0; i < n; i++) {
			char a, b;
			cin >> a >> b;

			if ((a == 'R' && b == 'S') || (a == 'P' && b == 'R') || (a == 'S' && b == 'P'))
				p1++;
			else if ((b == 'R' && a == 'S') || (b == 'P' && a == 'R') || (b == 'S' && a == 'P'))
				p2++;
		}

		if (p1 > p2)
			cout << "Player 1";
		else if (p1 < p2)
			cout << "Player 2";
		else
			cout << "TIE";
		cout << endl;
	}
}