#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int left = 0;
	int maxi = 0;
	
	for (int i = 0; i < n; i++) {
		if (arr[i] < arr[left])
			left = i;

		maxi = max(maxi, arr[i] - arr[left]);
		
		cout << maxi << " ";
	}
}