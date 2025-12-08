#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int y, c, p;
	cin >> y >> c >> p;

	c /= 2;
	y = min(y, p);

	cout << min(y, c);
}