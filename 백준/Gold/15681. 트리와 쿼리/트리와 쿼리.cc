/*
[트리DP, DFS]

정점 U를 루트로 하는 서브트리에 속한 정점의 수를 출력
정점의 수가 많으니까 인접행렬하면 터짐 -> 인접그래프

visited 처리 순서 잘해주기

왜 자꾸 시간초과 뜸? 개빢침 ㄹㅇ


*/

#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

int n, r, q;
vector<vector<int>> graph;
vector<int> DP;
vector<int> visited;

int FindDP(int num) {
	// DP[num]을 찾자

	// 이미 구함
	if (DP[num] != 0)
		return DP[num];

	// num의 자식 노드들을 전부 방문
	// 내 거
	DP[num] = 1;
	visited[num] = 1;

	// 자식 노드들 방문
	for (int i = 0; i < graph[num].size(); i++) {
		int next = graph[num][i];

		// 연결돼 있는데 이미 방문한 거면 부모노드임
		// 방문 안 했으면 자식이니까 또 내려가기
		if (!visited[next]) {
			visited[next] = 1;
			DP[num] += FindDP(next);
		}
	}
	return DP[num];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> r >> q;
	graph.resize(n + 1);
	visited.resize(n + 1);
	DP.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// DFS를 돌리면서...
	visited[r] = 1;
	FindDP(r);

	for (int i = 0; i < q; i++) {
		int u;
		cin >> u;
		cout << DP[u] << endl;
	}
}