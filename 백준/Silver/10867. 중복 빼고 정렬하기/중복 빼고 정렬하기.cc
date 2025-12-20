#include <iostream>
#include <algorithm>
using namespace std;

#define OFFSET 1000

int arr[2 * OFFSET + 1];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		arr[num + OFFSET]++;
	}

	for (int i = 0; i < 2 * OFFSET + 1; i++)
		if (arr[i])
			cout << i - OFFSET << " ";
}