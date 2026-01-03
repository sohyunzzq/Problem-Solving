#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	bool korea = false;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "yonsei" && korea)
			cout << "Yonsei Lost...";
		else if (s == "yonsei" && !korea)
			cout << "Yonsei Won!";
		else if (s == "korea")
			korea = true;
	}
}