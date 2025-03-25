/*
[트리DP]

DP[i]: i번 노드가 루트노드일 때 걸리는 최솟값

자식의 수가 많은 것부터 선택하기
다음 거 고를 때마다 +1, +2, ...
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

struct Node {
	int num;
	int dp_val;
	bool operator<(struct Node right) const {
		return dp_val > right.dp_val;
	}
};

int n;
vector<vector<int>> graph;
vector<int> DP;

int FindDP(int num) {
	// DP[num]을 찾아야 함
	if (DP[num] != -1)
		return DP[num];

	// 내가 리프노드
	if (graph[num].size() == 0)
		return DP[num] = 0;

	// 모든 자식 구하기
	vector<struct Node> children(graph[num].size());
	for (int i = 0; i < graph[num].size(); i++) {
		int child = graph[num][i];

		children[i] = { child, FindDP(child) };
	}
	sort(children.begin(), children.end());
	
	// 자식들 돌며 max 계속 갱신
	int minute = 1;
	int max_min = 0;
	for (int i = 0; i < graph[num].size(); i++) {
		max_min = max(max_min, children[i].dp_val + (minute++));
	}

	return DP[num] = max_min;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	graph.resize(n);
	DP.resize(n + 1, -1);
	int p;
	// 하나 버리기 (항상 -1)
	cin >> p;
	for (int i = 1; i < n; i++) {
		cin >> p;

		graph[p].push_back(i);
	}

	int ans = FindDP(0);
	cout << ans;
}