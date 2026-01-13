#include <iostream>
using namespace std;

#define PI 3.14159

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	double d, w;
	int n;
	cin >> d >> w >> n;

	double circle = PI * d;

	cout << (n * w <= circle ? "YES" : "NO");
}