#include <iostream>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int arr[16];
	int idx = 0;
	for (int i = 0; i < 8; i++) {
		arr[idx++] = int(a[i] - '0');
		arr[idx++] = int(b[i] - '0');
	}

	for (int i = 0; i < 14; i++)
		for (int j = 0; j < 15 - i; j++)
			arr[j] = (arr[j] + arr[j + 1]) % 10;
	cout << arr[0] << arr[1];
}