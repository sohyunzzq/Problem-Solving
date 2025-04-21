/*
[완전탐색]

N이 크지 않아서 그냥 완탐 돌리면 될 듯..
백트래킹을 어떻게 하지?
1 2 3 4 만들 수 있는 모든 숫자를 만드는 문제
*/

#include <iostream>
#include <climits>
using namespace std;

int n;
int selected[11];
int num[11];
int arr[4];
long long min_val = INT_MAX;
long long max_val = -INT_MAX;

void Calc() {
	long long ans = num[0];
	for (int i = 0; i < n - 1; i++) {
		if (selected[i] == 1)
			ans += num[i + 1];
		else if (selected[i] == 2)
			ans -= num[i + 1];
		else if (selected[i] == 3)
			ans *= num[i + 1];
		else
			ans /= num[i + 1];
	}
	min_val = min(min_val, ans);
	max_val = max(max_val, ans);
}

void func(int curr) {
	if (curr == n - 1) {
		// 계산
		Calc();
		return;
	}

	for (int j = 0; j < 4; j++) {
		if (arr[j]) {
			selected[curr] = j + 1;
			arr[j]--;
			func(curr + 1);
			arr[j]++;
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < 4; i++)
		cin >> arr[i];

	func(0);

	cout << max_val << endl << min_val;
}