#include <iostream>
#include <cmath>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int a, b, c;
	while (1) {
		cin >> a >> b >> c;

		if (!a && !b && !c)
			break;

		int maxi = max(a, b);
		maxi = max(maxi, c);

		if (maxi >= (a + b + c - maxi))
			cout << "Invalid";
		else if (a == b && b == c)
			cout << "Equilateral";
		else if (a == b || b == c || c == a)
			cout << "Isosceles";
		else
			cout << "Scalene";
		cout << endl;
	}
}