#include <iostream>
#include <set>
using namespace std;
#define endl '\n'

multiset<int> ms;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		ms.clear();

		int k;
		cin >> k;

		for (int i = 0; i < k; i++) {
			char cmd;
			int n;
			cin >> cmd >> n;

			switch (cmd) {
			case 'I':
				ms.insert(n);
				break;
			case 'D':
				if (ms.empty())
					continue;

				if (n == 1) {
					ms.erase(--ms.end());
				}
				else if (n == -1)
					ms.erase(ms.begin());
			}
		}
		if (ms.empty())
			cout << "EMPTY";
		else
			cout << *(--ms.end()) << " " << *(ms.begin());
		cout << endl;
	}
}