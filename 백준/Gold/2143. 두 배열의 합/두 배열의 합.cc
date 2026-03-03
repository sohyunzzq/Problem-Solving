#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];

	int m;
	cin >> m;
	vector<int> B(m);
	for (int i = 0; i < m; i++)
		cin >> B[i];

	vector<int> A_sum;
	vector<int> B_sum;

	for (int i = 0; i < n; i++) {
		long long sum = 0;
		for (int j = i; j < n; j++) {
			sum += A[j];
			A_sum.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++) {
		long long sum = 0;
		for (int j = i; j < m; j++) {
			sum += B[j];
			B_sum.push_back(sum);
		}
	}
	
	sort(B_sum.begin(), B_sum.end());
	long long cnt = 0;
	for (int i = 0; i < A_sum.size(); i++) {
		int target = T - A_sum[i];

		int st = lower_bound(B_sum.begin(), B_sum.end(), target) - B_sum.begin();
		int en = upper_bound(B_sum.begin(), B_sum.end(), target) - B_sum.begin();

		cnt += en - st;
	}

	cout << cnt;
}