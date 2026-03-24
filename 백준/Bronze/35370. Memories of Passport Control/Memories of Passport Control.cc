#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int k, s;
	cin >> k >> s;

	cout << s / k + s % k;
}