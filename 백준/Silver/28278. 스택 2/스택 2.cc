#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<int> st;
	int cmd;
	for (int i = 0; i < n; i++) {
		cin >> cmd;

		switch (cmd) {
		case 1:
			int x;
			cin >> x;
			st.push_back(x);
			break;
		case 2:
			if (st.size()) {
				cout << st.back() << endl;
				st.pop_back();
			}
			else
				cout << -1 << endl;
			break;
		case 3:
			cout << st.size() << endl;
			break;
		case 4:
			cout << (st.size() == 0 ? 1 : 0) << endl;
			break;
		case 5:
			cout << (st.size() ? st.back() : -1) << endl;
		}
	}
}