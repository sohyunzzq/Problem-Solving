#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Cmp {
	bool operator() (const int& a, const int& b) {
		return a > b;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<int> A(n);
	vector<int> B(n);

	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++)
		cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), Cmp());

	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += A[i] * B[i];

	cout << ans;
}