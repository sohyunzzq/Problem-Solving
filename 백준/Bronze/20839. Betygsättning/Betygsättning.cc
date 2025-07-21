#include <iostream>
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;

	int a, b, c;
	cin >> a >> b >> c;

	if (a >= x && b >= y && c >= z)
		cout << "A";
	else if (a >= ((x + 1) / 2) && b >= y && c >= z)
		cout << "B";
	else if (b >= y && c >= z)
		cout << "C";
	else if (b >= ((y + 1) / 2) && c >= z)
		cout << "D";
	else
		cout << "E";
}