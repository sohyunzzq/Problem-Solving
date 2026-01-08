#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	cout << char(((n - 1) % 8) + 'a') << (n % 8 == 0 ? n / 8 : (n + 8) / 8);
}