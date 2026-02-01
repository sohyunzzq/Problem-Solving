#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;

double GetSlope(int idx1, int idx2) {
	int x1 = idx1, y1 = arr[idx1];
	int x2 = idx2, y2 = arr[idx2];

	return double(y1 - y2) / (x1 - x2);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	arr.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> building(n, 0);

	// 우측 보기
	for (int i = 0; i < n - 1; i++) {
		double max_slope = GetSlope(i, i + 1);
		building[i]++;

		for (int j = i + 2; j < n; j++) {
			double slope = GetSlope(i, j);
			if (slope > max_slope) {
				max_slope = slope;
				building[i]++;
			}
		}
	}

	// 좌측 보기
	for (int i = n - 1; i >= 1; i--) {
		double max_slope = -GetSlope(i, i - 1);
		building[i]++;

		for (int j = i - 2; j >=0; j--) {
			double slope = -GetSlope(i, j);
			if (slope > max_slope) {
				max_slope = slope;
				building[i]++;
			}
		}
	}

	sort(building.begin(), building.end(), greater<>());

	cout << building[0];
}