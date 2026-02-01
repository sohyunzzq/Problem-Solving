#include <iostream>
#include <vector>
using namespace std;

#define MAX_NM 500
#define MAX_H 256

int n, m, b;
vector<vector<int>> arr;
int t = MAX_NM * MAX_NM * 2 * MAX_H, h = 0;

void Cal(int goal) {
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 이미 오래 걸림
			if (tmp > t)
				return;

			// 블록 제거
			if (arr[i][j] > goal) { 
				tmp += (arr[i][j] - goal) * 2;
			}
			// 블록 쌓기
			else {
				tmp += (goal - arr[i][j]);
			}
		}
	}
	if (tmp <= t) {
		t = tmp;
		h = goal;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> b;
	
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		arr[i].resize(m);
	}

	int sum = b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			sum += arr[i][j];
		}
	}

	// 가능한 최대 높이
	int max_h = sum / (n * m);

	for (int i = 0; i <= max_h; i++) {
		// 높이를 전부 i로 하기
		Cal(i);
	}

	cout << t << " " << h;
}