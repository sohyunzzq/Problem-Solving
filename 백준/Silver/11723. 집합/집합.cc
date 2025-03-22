/*
파이썬으로 걍 생각나는 대로 했을 때 시초 났음
cpp로 해도 같을 거 같긴 한데; 일단 도전
*/

#include <iostream>
using namespace std;

#define endl "\n";

bool S[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
	cin >> m;

	for (int t = 0; t < m; t++) {
		string str;
		cin >> str;

		if (str == "add") {
			int n;
			cin >> n;

			S[n] = 1;
		}
		else if (str == "remove") {
			int n;
			cin >> n;

			S[n] = 0;
		}
		else if (str == "check") {
			int n;
			cin >> n;

			cout << S[n] << endl;
		}
		else if (str == "toggle") {
			int n;
			cin >> n;

			S[n] = !S[n];
		}
		else if (str == "all") {
			for (int i = 1; i <= 20; i++)
				S[i] = 1;
		}
		else if (str == "empty") {
			for (int i = 1; i <= 20; i++)
				S[i] = 0;
		}
	}
}