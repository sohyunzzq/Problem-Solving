#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

vector<long long> DP;

long long FindDP(int num) {
	if (DP[num] != 0)
		return DP[num];

	if (num == 1)
		return DP[num] = 1;
	if (num == 2)
		return DP[num] = 3;
	
	return DP[num] = (FindDP(num - 1) + FindDP(num - 2) * 2) % 10007;
}

int main() {
	int n;
	cin >> n;

	DP.resize(n + 1, 0);
	
	cout << FindDP(n);
}