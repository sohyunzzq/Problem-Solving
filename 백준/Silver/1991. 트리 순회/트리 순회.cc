#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n;
vector<pair<int, int>> graph;

void pre(int curr) {
	cout << char(curr + 'A');

	if (graph[curr].first)
		pre(graph[curr].first);
	if (graph[curr].second)
		pre(graph[curr].second);
}

void in(int curr) {
	if (graph[curr].first)
		in(graph[curr].first);

	cout << char(curr + 'A');
	
	if (graph[curr].second)
		in(graph[curr].second);
}

void post(int curr) {
	if (graph[curr].first)
		post(graph[curr].first);
	if (graph[curr].second)
		post(graph[curr].second);

	cout << char(curr + 'A');
}

int main() {
	fastio;

	cin >> n;
	graph.resize(n + 1);

	for (int i = 0; i < n; i++) {
		char p, l, r;
		cin >> p >> l >> r;

		if (l != '.')
			graph[p - 'A'].first = l - 'A';
		if (r != '.')
			graph[p - 'A'].second = r - 'A';
	}

	pre(0);
	cout << endl;
	in(0);
	cout << endl;
	post(0);
	cout << endl;
}