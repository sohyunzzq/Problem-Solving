#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a <= b)
		cout << "high speed rail";
	else
		cout << "flight";
}