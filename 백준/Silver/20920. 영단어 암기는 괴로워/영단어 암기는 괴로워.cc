#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

struct Cmp {
	bool operator() (const pair<string, int> &a, const pair<string, int> &b) {
		if (a.second != b.second)
			return a.second > b.second;

		if (a.first.size() != b.first.size())
			return a.first.size() > b.first.size();

		return a.first < b.first;
	}
};

map<string, int> voca;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s.size() < m)
			continue;

		voca[s]++;
	}

	vector<pair<string, int>> v(voca.begin(), voca.end());
	sort(v.begin(), v.end(), Cmp());

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << endl;
}