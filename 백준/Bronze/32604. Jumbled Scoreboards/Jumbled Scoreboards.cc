#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;

	bool ans = true;

	int pa = 0, pb = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		if (pa > a || pb > b)
			ans = false;

		pa = a;
		pb = b;
	}

	cout << (ans ? "yes" : "no");
}