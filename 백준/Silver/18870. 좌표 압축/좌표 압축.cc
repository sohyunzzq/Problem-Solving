#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	vector<int> num(n);
	vector<int> tmp(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		tmp[i] = num[i];
	}

	map<int, int> match;
	sort(tmp.begin(), tmp.end());
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (!match.count(tmp[i]))
			match[tmp[i]] = idx++;
	}

	for (int i = 0; i < n; i++)
		cout << match[num[i]] << " ";
}