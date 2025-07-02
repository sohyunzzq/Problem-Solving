#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> choose;
long long sum;

void func(int curr) {
	if (curr == 2) {
		for (int i = 0; i < 2; i++)
			sum += choose[i];
		return;
	}

	for (int i = 0; i <= n; i++) {
		if (curr == 0 || choose[curr - 1] <= i) {
			choose.push_back(i);
			func(curr + 1);
			choose.pop_back();
		}
	}
}

int main() {
	cin >> n;
	func(0);
	cout << sum;
}