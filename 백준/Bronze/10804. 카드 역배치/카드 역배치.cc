#include <iostream>
using namespace std;

int main() {
	int arr[21];
	for (int i = 1; i <= 20; i++)
		arr[i] = i;

	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;

		int len = (a + b) / 2;
		for (int j = a; j <= len; j++) {
			int tmp = arr[j];
			arr[j] = arr[b];
			arr[b--] = tmp;
		}
	}

	for (int i = 1; i <= 20; i++)
		cout << arr[i] << " ";
}