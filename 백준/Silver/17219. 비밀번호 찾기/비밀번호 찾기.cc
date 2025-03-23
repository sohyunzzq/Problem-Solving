/*
빠른 입출력을 사용하고
map 자료구조를 써주자
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, string> pwd;

	for (int i = 0; i < n; i++) {
		string site, p;
		cin >> site >> p;

		pwd.insert({ site, p });
	}

	for (int i = 0; i < m; i++) {
		string site;
		cin >> site;

		cout << pwd[site] << '\n';
	}
}