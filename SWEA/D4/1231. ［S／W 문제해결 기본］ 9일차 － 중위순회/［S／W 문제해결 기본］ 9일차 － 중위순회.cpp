#include <iostream>
#include <string>
using namespace std;

#define N_SZ 101

int n;
char ch[N_SZ];

void DFS(int curr) {
	if (curr > n)
		return;

	DFS(curr * 2);
	cout << ch[curr];
	DFS(curr * 2 + 1);
}

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;

			string s;
			getline(cin, s);

			ch[i + 1] = s[1];
		}

		cout << "#" << tc << " ";
		DFS(1);
		cout << endl;
	}
}