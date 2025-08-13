#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	int a = abs(s1[0] - s2[0]);
	int b = abs(s1[1] - s2[1]);

	cout << min(a, b) << " " << max(a, b);
}