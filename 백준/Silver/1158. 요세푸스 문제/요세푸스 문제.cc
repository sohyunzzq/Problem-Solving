/*
리스트로 구현해보기...
prev가 필요 없을 듯..
*/

#include <iostream>
#include <vector>
using namespace std;

#define NODE_SZ 5001
#define endl '\n'

struct Node {
	int data;
	Node* next;

	Node(int data) :data(data), next(nullptr) {}
};

int n, k;
vector<int> ans;
Node* p;

class LinkedList {
	Node* head;
	Node* tail;
	vector<Node*> Nodes;
	int cnt;

public:
	LinkedList() :head(nullptr), tail(nullptr), cnt(0) {
		Nodes.resize(NODE_SZ, nullptr);
	}

	Node* MakeNode(int data) {
		return Nodes[cnt++] = new Node(data);
	}

	void Init(int n) {
		// 1부터 n까지 전부 넣기
		Node* start = MakeNode(1);
		head = start;
		tail = start;
		p = start;

		if (n == 1) {
			start->next = start;
			return;
		}

		Node* cur = start;
		for (int i = 2; i < n; i++) {
			Node* temp = MakeNode(i);
			cur->next = temp;
			cur = cur->next;
		}
		
		Node* last = MakeNode(n);
		cur->next = last;
		last->next = head;
		tail = last;
	}

	void Delete() {
		// k번째 없애기
		if (head == tail) {
			ans.push_back(head->data);
			return;
		}

		Node* cur = p;
		for (int i = 1; i < k-1; i++)
			cur = cur->next;
		Node* temp = cur;
		if (k > 1)
			cur = cur->next;
		ans.push_back(cur->data);
		temp->next = cur->next;
		p = temp->next;
	}
};

int main() {
	cin >> n >> k;
	LinkedList list;

	list.Init(n);
	
	while (ans.size() != n) {
		list.Delete();
	}

	cout << "<";
	for (int i = 0; i < n - 1; i++)
		cout << ans[i] << ", ";
	cout << ans[n - 1] << ">";
}