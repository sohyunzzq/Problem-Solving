#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, a, b;
	cin >> n >> m >> a >> b;

	int need = max(0, n * 3 - m);
	cout << (need == 0 ? 0 : need * a + b);
}