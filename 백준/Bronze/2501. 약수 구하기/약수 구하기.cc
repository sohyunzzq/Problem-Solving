#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> arr;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) 
		if (n % i == 0) 
			arr.push_back(i);

	sort(arr.begin(), arr.end());

	cout << (arr.size() >= k - 1? arr[k - 1] : 0);
}