#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	switch (x % 3) {
	case 0: {
		cout << "S";
		break;
	}
	case 1: {
		cout << "U";
		break;
	}
	case 2: {
		cout << "O";
		break;
	}
	}
}