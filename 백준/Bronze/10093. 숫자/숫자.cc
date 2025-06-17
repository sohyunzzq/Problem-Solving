#include <iostream>
using namespace std;

int main() {
	long long A, B;
	cin >> A >> B;

	if (A > B) {
		long long tmp = A;
		A = B;
		B = tmp;
	}

	if (A == B)
		cout << 0;
	else {
		// A < B
		int cnt = B - A - 1;
		cout << cnt << endl;
		for (long long i = A + 1; i < B; i++)
			cout << i << " ";
	}
}