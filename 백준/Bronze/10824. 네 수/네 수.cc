#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	string a, b, c, d;
	cin >> a >> b >> c >> d;

	string n1 = a + b;
	string n2 = c + d;

	long long num1 = stol(n1);
	long long num2 = stol(n2);

	cout << num1 + num2;
}