#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		if (str == "Poblano")
			ans += 1500;
		else if (str == "Mirasol")
			ans += 6000;
		else if (str == "Serrano")
			ans += 15500;
		else if (str == "Cayenne")
			ans += 40000;
		else if (str == "Thai")
			ans += 75000;
		else
			ans += 125000;
	}
	cout << ans;
}