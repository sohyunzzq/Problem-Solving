#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

string func;
vector<int> arr;
int n;
int st, en;
bool err = false;
bool emp = false;

bool IsNum(char c) {
	int tmp = int(c - '0');

	return (0 <= tmp && tmp <= 9);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		arr.clear();
		err = false;
		emp = false;

		cin >> func;
		cin >> n;
		string s;
		cin >> s;

		int idx = 0;
		while(idx < s.size()) {
			int tmp = 0;
			while (idx < s.size() && IsNum(s[idx])) {
				tmp *= 10;
				tmp += int(s[idx++] - '0');
			}
			if (tmp)
				arr.push_back(tmp);

			idx++;
		}
		
		int d = 0;
		for (int i = 0; i < func.size(); i++) {
			if (func[i] == 'D')
				d++;
		}
		if (d > arr.size())
			err = true;
		else if (d==arr.size())
			emp = true;

		int st = 0, en = n - 1;
		if (!emp) {
			for (int i = 0; i < func.size(); i++) {
				if (func[i] == 'R') {
					int tmp = st;
					st = en;
					en = tmp;
				}
				else {
					if (st <= en) {
						st++;
					}
					else if (st > en) {
						st--;
					}
				}
			}
		}

		if (err)
			cout << "error" << endl;
		else {
			cout << '[';

			if (emp)
				;
			else if (st <= en) {
				for (int i = st; i < en; i++)
					cout << arr[i]<<",";
				cout << arr[en];
			}
			else if (st > en ){
				for (int i = st; i > en; i--)
					cout << arr[i] << ",";
				cout << arr[en];
			}

			cout << ']' << endl;
		}
	}
}