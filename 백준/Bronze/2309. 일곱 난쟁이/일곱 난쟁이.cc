#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[9];
	for (int i = 0; i < 9; i++)
		cin >> arr[i];

	int sum = 0;
	for (int i = 0; i < 9; i++)
		sum += arr[i];

	sort(arr, arr + 9);

	int diff = sum - 100;

	int left = 0;
	int right = 8;

	while (left < right) {
		int temp = arr[left] + arr[right];

		if (diff < temp)
			right--;
		else if (diff > temp)
			left++;
		else
			break;
	}

	for (int i = 0; i < 9; i++) {
		if (i == left || i == right)
			continue;
		cout << arr[i] << endl;
	}
}