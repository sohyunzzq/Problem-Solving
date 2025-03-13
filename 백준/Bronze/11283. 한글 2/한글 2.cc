#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int n = ((s[0] & 255) - 234) * 4096 + ((s[1] & 255) - 176) * 64 + (s[2] & 255) - 127;
	cout << n;
}