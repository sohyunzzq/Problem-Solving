#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Cmp {
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
		return a.first < b.first;
	}
};

int n;
vector<pair<int, int>> arr;
vector<int> LIS;

void BinarySearch(int left, int right, int target) {
	// lowerbound 찾기
	while (left <= right) {
		int mid = (left + right) / 2;

		if (LIS[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}

	}
	if (LIS[left] < target)
		LIS[left + 1] = target;
	else
		LIS[left] = target;
}

void GetLIS() {
	LIS.push_back(arr[0].second);
	for (int i = 1; i < n; i++) {
		if (arr[i].second > LIS[LIS.size() - 1]) {
			LIS.push_back(arr[i].second);
		}
		else {
			BinarySearch(0, LIS.size() - 1, arr[i].second);
		}
	}
}

int main() {
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), Cmp());

	// second들을 보면서, LIS의 길이를 빼주면 됨
	GetLIS();

	cout << n - LIS.size();
}