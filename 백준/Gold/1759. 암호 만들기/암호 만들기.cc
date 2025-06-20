/*
[백트래킹]

한 개 모음과 최소 두 개의 자음
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> alpha;
vector<char> choose;
int selected[26];

void func(int curr) {
	if (curr == l) {
		int aeiou = 0;
		int other = 0;

		for (int i = 0; i < l; i++) {
			if (choose[i] == 'a' ||
				choose[i] == 'e' ||
				choose[i] == 'i' ||
				choose[i] == 'o' ||
				choose[i] == 'u')
				aeiou++;
			else
				other++;
		}
		
		if (aeiou >= 1 && other >= 2) {
			for (int i = 0; i < l; i++) {
				cout << choose[i];
			}
			cout << endl;
		}
	}

	for (int i = 0; i < c; i++) {
		if (curr == 0 || choose[curr - 1] < alpha[i]) {
			if (selected[alpha[i] - 'a'] == 0) {
				selected[alpha[i] - 'a'] = 1;
				choose.push_back(alpha[i]);
				func(curr + 1);
				selected[alpha[i] - 'a'] = 0;
				choose.pop_back();
			}
		}
	}
}

int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char a;
		cin >> a;

		alpha.push_back(a);
	}

	sort(alpha.begin(), alpha.end());
	
	func(0);
}