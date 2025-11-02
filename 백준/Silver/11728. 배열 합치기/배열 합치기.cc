#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> A(n);
	vector<int> B(m);

	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < m; i++)
		cin >> B[i];

	int left = 0, right = 0;

	while (1) {
		if (A[left] < B[right])
			cout << A[left++] << " ";
		else
			cout << B[right++] << " ";

		if (left == n) {
			while (right < m)
				cout << B[right++] << " ";
			break;
		}
		else if (right == m) {
			while (left < n)
				cout << A[left++] << " ";
			break;
		}
	}
}