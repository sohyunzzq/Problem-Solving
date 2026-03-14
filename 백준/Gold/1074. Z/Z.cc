#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;

int Chop(int n, int r, int c) {
	if (n == 0)
		return 0;

	int half = pow(2, n - 1);
	int area = half * half;

	// 왼쪽 위
	if (r < half && c < half)
		return Chop(n - 1, r, c);
	// 오른쪽 위
	else if (r < half && c >= half)
		return area + Chop(n - 1, r, c - half);
	// 왼쪽 아래
	else if (r >= half && c < half)
		return 2 * area + Chop(n - 1, r - half, c);
	// 오른쪽 아래
	else 
		return 3 * area + Chop(n - 1, r - half, c - half);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> r >> c;

	cout << Chop(n, r, c);
}