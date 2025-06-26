#include <iostream>
#include <vector>
using namespace std;

vector<int> choose;
int nums[5];
long long ans = 1;

int GetLCM(int a, int b) {
	long long result;

	int mn = min(a, b);
	int mx = max(a, b);

	for (int i = mn; i <= mn * mx; i+=mn) {
		if (i % mx == 0) {
			result = i;
			break;
		}
	}

	return result;
}

void func(int index) {
	if (choose.size() == 3) {
		long long temp = GetLCM(choose[0], choose[1]);
		temp = GetLCM(temp, choose[2]);
		ans = min(ans, temp);
	}

	for (int i = index; i < 5; i++) {
		choose.push_back(nums[i]);
		func(i + 1);
		choose.pop_back();
	}
}

int main() {
	for (int i = 0; i < 5; i++)
		cin >> nums[i];

	for (int i = 0; i < 5; i++)
		ans *= nums[i];

	func(0);

	cout << ans;
}