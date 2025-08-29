#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int sum = a + b;
	string s = to_string(sum);

	cout << s.size();
}