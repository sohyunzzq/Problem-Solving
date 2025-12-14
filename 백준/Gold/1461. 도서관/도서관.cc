#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> positions(n);
	for (int i = 0; i < n; i++)
		cin >> positions[i];

	sort(positions.begin(), positions.end());

	long long sum = 0;

	// 음수 부분
	int idx = 0;
	while (idx < n && positions[idx] < 0) {
		sum += abs(positions[idx]);
		idx += m;
	}

	// 양수 부분
	idx = n - 1;
	while (idx >= 0 && positions[idx] > 0) {
		sum += positions[idx];
		idx -= m;
	}

	// 왕복
	sum *= 2;

	// 제일 큰 쪽은 한 번만 가기
	sum -= max(abs(positions[0]), positions[n - 1]);

	cout << sum;
}