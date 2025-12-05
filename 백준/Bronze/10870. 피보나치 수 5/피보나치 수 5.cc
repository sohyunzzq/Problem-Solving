#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	long long Fibo[25];

	Fibo[0] = 0;
	Fibo[1] = 1;
	
	for (int i = 2; i <= n; i++)
		Fibo[i] = Fibo[i - 2] + Fibo[i - 1];

	cout << Fibo[n];
}