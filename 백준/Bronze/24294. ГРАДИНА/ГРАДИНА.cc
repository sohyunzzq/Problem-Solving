#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int w1, h1, w2, h2;
	cin >> w1 >> h1 >> w2 >> h2;

	int w = max(w1, w2);
	int h = h1 + h2;

	cout << w * 2 + h * 2 + 4;
}