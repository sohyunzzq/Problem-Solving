#include <iostream>
using namespace std;
#define endl '\n'

#define SZ 11

int statistics[SZ][SZ];
int max_sum;
bool path[SZ];

void Init() {
	for (int i = 0; i < SZ; i++)
		for (int j = 0; j < SZ; j++)
			statistics[i][j] = 0;
	max_sum = 0;
	for (int i = 0; i < SZ; i++)
		path[i] = false;
}

void func(int curr, int sum) {
	// curr번줄 확정 후 보내기
	if (curr == SZ) {
		max_sum = max(max_sum, sum);
		return;
	}

	for (int i = 0; i < SZ; i++) {
		if (!path[i] && statistics[curr][i] > 0) {
			path[i] = true;
			func(curr + 1, sum + statistics[curr][i]);
			path[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Init();

		for (int i = 0; i < SZ; i++) {
			for (int j = 0; j < SZ; j++) {
				cin >> statistics[i][j];
			}
		}

		func(0, 0);
		cout << max_sum << endl;
	}
}