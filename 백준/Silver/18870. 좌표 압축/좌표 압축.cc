#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
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
		if (match.count(tmp[i]))
			continue;
		
		match[tmp[i]] = idx++;
	}

	for (int i = 0; i < n; i++)
		cout << match[num[i]] << " ";
}