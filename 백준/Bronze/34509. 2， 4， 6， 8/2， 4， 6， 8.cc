#include <iostream>
using namespace std;

int main() {
	for (int i = 10; i <= 99; i++) {
		if (i / 10 == 8 || i % 10 == 8)
			continue;

		int tmp = i / 10 + i % 10;
		if (tmp % 6 != 0)
			continue;

		tmp = i % 10 * 10 + i / 10;
		if (tmp % 4 != 0)
			continue;

		cout << i;
		break;
	}
}