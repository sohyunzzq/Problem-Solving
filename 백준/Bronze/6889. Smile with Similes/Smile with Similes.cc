#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> adj(n);
	vector<string> noun(m);

	for (int i = 0; i < n; i++)
		cin >> adj[i];

	for (int i = 0; i < m; i++)
		cin >> noun[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << adj[i] << " as " << noun[j] << endl;
		}
	}
}