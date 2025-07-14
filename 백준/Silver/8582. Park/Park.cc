/*
서쪽: [0, i]
동쪽: [i, n-1]
위 범위에서 최댓값 구하기
*/

#include <iostream>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

int main() {
	fastio;

	int n;
	cin >> n;

	vector<int> w(n);
	for (int i = 0; i < n; i++)
		cin >> w[i];

	vector<int> left(n);
	vector<int> right(n);

	int m = 0;
	for (int i = 0; i < n; i++) {
		m = max(m, w[i]);
		left[i] = m;
	}

	int M = 0;
	for (int i = n - 1; i >= 0; i--) {
		M = max(M, w[i]);
		right[i] = M;
	}

	for (int i = 0; i < n; i++)
		cout << left[i] << " " << right[i] << endl;
}