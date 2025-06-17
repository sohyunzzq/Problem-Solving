#include <iostream>
using namespace std;

int main() {
	for (int i = 0; i < 3; i++) {
		int arr[2] = {};
		for (int i = 0; i < 4; i++) {
			int n;
			cin >> n;

			arr[n]++;
		}

		switch (arr[0]) {
		case 0:
			cout << "E";
			break;
		case 1:
			cout << "A";
			break;
		case 2:
			cout << "B";
			break;
		case 3:
			cout << "C";
			break;
		case 4:
			cout << "D";
			break;
		}
		cout << "\n";
	}
}