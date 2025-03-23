/*
다음에 주어지는 수가 배수라고 명시돼 있어서
단순히 그리디하게 접근하면 됨
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		cnt += k / coins[i];
		k %= coins[i];
	}
	
	cout << cnt;
}