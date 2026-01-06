#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	bool flag = false;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "anj")
			flag = true;
	}

	cout << (flag ? "뭐야;" : "뭐야?");
}