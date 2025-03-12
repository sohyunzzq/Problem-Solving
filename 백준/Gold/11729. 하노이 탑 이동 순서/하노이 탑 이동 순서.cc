#include <iostream>
#include <cmath>
using namespace std;

#define endl "\n"

void Hanoi(int n, int from, int tmp, int to) {
	if (n == 1) {
		cout << from << " " << to << endl;
	}
	else {
		Hanoi(n - 1, from, to, tmp);
		cout << from << " " << to << endl;
		Hanoi(n - 1, tmp, from, to);
	}
}

int main() {
	int n;
	cin >> n;

	// 최소 2^n-1번
	cout << int(pow(2, n)) - 1 << endl;
	Hanoi(n, 1, 2, 3);
}