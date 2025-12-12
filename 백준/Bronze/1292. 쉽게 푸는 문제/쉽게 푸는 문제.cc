#include <iostream>
using namespace std;

int main() {
	long long arr[1001];

	int index = 1;
	int num = 1;
	while (index <= 1000) {
		for (int i = 0; i < num; i++) {
			if (index > 1000)
				break;
			arr[index++] = num;
		}
		num++;
	}

	int a, b;
	cin >> a >> b;

	long long sum = 0;
	for (int i = a; i <= b; i++)
		sum += arr[i];

	cout << sum;
}