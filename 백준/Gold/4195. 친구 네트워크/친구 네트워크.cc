#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define endl '\n'

#define MAX_F 100'000*2

map<string, string> uf;
map<string, int> cnt;

string Find(string name) {
	if (uf[name] == name)
		return name;
	return uf[name] = Find(uf[name]);
}

void Union(string n1, string n2) {
	string N1 = Find(n1);
	string N2 = Find(n2);

	if (N1 == N2)
		return;

	cnt[N2] += cnt[N1];
	uf[N1] = N2;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		uf.clear();
		cnt.clear();

		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			string n1, n2;
			cin >> n1 >> n2;

			if (cnt[n1] < 1) {
				uf[n1] = n1;
				cnt[n1] = 1;
			}

			if (cnt[n2] < 1) {
				uf[n2] = n2;
				cnt[n2] = 1;
			}

			string p1 = Find(n1);
			string p2 = Find(n2);

			Union(p1, p2);
			cout << cnt[Find(p1)] << endl;
		}
	}
}