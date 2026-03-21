#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	int A, B, C, a, b, c;
	cin >> A >> B >> C;
	a = A, b = B, c = C;

	int abc[2][3] = { A, B, C, A, B, C };

	for (int i = 1; i < n; i++) {
		cin >> A >> B >> C;
		a = A;
		b = B;
		c = C;

		A += max(abc[0][0], abc[0][1]);
		B += max(max(abc[0][0], abc[0][1]), abc[0][2]);
		C += max(abc[0][1], abc[0][2]);

		a += min(abc[1][0], abc[1][1]);
		b += min(min(abc[1][0], abc[1][1]), abc[1][2]);
		c += min(abc[1][1], abc[1][2]);

		abc[0][0] = A;
		abc[0][1] = B;
		abc[0][2] = C;

		abc[1][0] = a;
		abc[1][1] = b;
		abc[1][2] = c;
	}

	cout << max(max(A, B), C) << " " << min(min(a, b), c);
}