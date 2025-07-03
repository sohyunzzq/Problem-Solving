/*
post의 마지막 노드는 무조건 루트
in에서 루트 인덱스를 찾고, 인덱스 기준 left right 나누기

post도 left, right 나눌 건데, in과 개수가 똑같음 -> 인덱스로 나눠기
계속 재귀 돌면서 위를 반복하면 될 듯?
*/

#include <iostream>
#include <vector>
using namespace std;

#define N_SZ 100'001

#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n;
vector<int> in;
vector<int> post;
vector<int> pre;

void MiddleNode(int start, int end) {
	if (start > end)
		return;

	if (start == end) {
		pre.push_back(in[start]);
		return;
	}

	int sz = end - start + 1;
	int index = start + sz / 2;
	pre.push_back(in[index]);
	MiddleNode(start, index - 1);
	MiddleNode(index + 1, end);
}

void Tree(int in_st, int in_en, int po_st, int po_en) {
	if (in_st > in_en)
		return;

	if (in_st == in_en) {
		pre.push_back(in[in_st]);
		return;
	}
	
	int root = post[po_en];
	pre.push_back(root);

	int index;
	for (int i = in_st; i <= in_en; i++)
		if (in[i] == root) {
			index = i;
			break;
		}

	int tmp = index - in_st;
	Tree(in_st, index - 1, po_st, po_st + tmp - 1);
	Tree(index + 1, in_en, po_st + tmp, po_en - 1);
}

int main() {
	fastio;
	cin >> n;

	in.resize(n +  1);
	post.resize(n + 1);

	for (int i = 0; i < n; i++)
		cin >> in[i];
	for (int i = 0; i < n; i++)
		cin >> post[i];

	Tree(0, n - 1, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << pre[i] << " ";
}