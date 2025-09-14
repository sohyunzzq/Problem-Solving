#include <iostream>
using namespace std;

#define SZ 7

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s[SZ];
	int n[SZ];

	for (int i = 0; i < SZ; i++)
		cin >> s[i] >> n[i];

	int max_val = 0, max_index = -1;
	for (int i = 0; i < SZ; i++) {
		if (n[i] > max_val) {
			max_val = n[i];
			max_index = i;
		}
	}

	cout << s[max_index];
}