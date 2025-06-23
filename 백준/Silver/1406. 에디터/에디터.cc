/*
[연결 리스트 (노드풀)]

어디에 삽입할지 숫자로 주어지지 않음
커서를 전역으로 기억해두고 있어야 하는데 어떻게 하지?

기존 인덱스(int) 비교가 아닌 메인커서와 주소를 비교하는 방식으로

ab|
커서는 내 왼쪽 글자를 가리킴

|ab
이럴 경우, 커서를 표시할 방법 없으므로 맨 앞에 더미노드를 헤드로 넣기

영어 소문자만 들어오니까, X로 넣음

prev가 있으면, 선형 탐색을 할 필요가 없어서 시간복잡도가 줄어듦
*/

#include <iostream>
#include <vector>
using namespace std;

#define NODE_MAX 600005
#define endl '\n'

struct Node {
	char data;
	Node* next;
	Node* prev;
	Node(char data) : data(data), next(nullptr), prev(nullptr) {}
};

Node* MAIN_CURSOR;

class LinkedList {
	Node* head;
	Node* tail;
	vector<Node*> Nodes;
	int NodeCnt;

public:
	LinkedList() : head(nullptr), tail(nullptr), NodeCnt(0) {
		Nodes.resize(NODE_MAX, nullptr);
	}

	Node* MakeNode(char data) {
		return Nodes[NodeCnt++] = new Node(data);
	}

	// 처음에 입력 받기
	void Init(string s) {
		head = MakeNode('X');

		Node* cur = head;
		for (int i = 0; i < s.size(); i++) {
			Node* temp = MakeNode(s[i]);
			temp->prev = cur;
			temp->next = cur->next;
			cur->next = temp;
			cur = temp;
		}

		MAIN_CURSOR = cur;
		tail = MAIN_CURSOR;
	}

	void Left() {
		// 맨 앞
		if (MAIN_CURSOR == head)
			return;

		MAIN_CURSOR = MAIN_CURSOR->prev;
	}

	void Right() {
		// 맨 뒤
		if (MAIN_CURSOR == tail)
			return;

		MAIN_CURSOR = MAIN_CURSOR->next;
	}

	// MAIN_CURSOR 전전에서 이어줘야 함
	void Backspace() {
		// 맨 앞
		if (MAIN_CURSOR == head)
			return;

		// 맨 뒤
		if (MAIN_CURSOR == tail) {
			MAIN_CURSOR->prev->next = nullptr;
			MAIN_CURSOR = MAIN_CURSOR->prev;

			tail = MAIN_CURSOR;
			return;
		}
		
		MAIN_CURSOR->prev->next = MAIN_CURSOR->next;
		MAIN_CURSOR->next->prev = MAIN_CURSOR->prev;
		MAIN_CURSOR = MAIN_CURSOR->prev;
	}

	// MC 다음에 이어주기
	void Plus(char data) {
		Node* temp = MakeNode(data);
		
		// 맨 뒤
		if (MAIN_CURSOR == tail) {
			MAIN_CURSOR->next = temp;
			temp->prev = MAIN_CURSOR;
			MAIN_CURSOR = temp;
			tail = MAIN_CURSOR;
			return;
		}

		temp->prev = MAIN_CURSOR;
		temp->next = MAIN_CURSOR->next;
		MAIN_CURSOR->next->prev = temp;
		MAIN_CURSOR->next = temp;
		MAIN_CURSOR = temp;
	}

	void PrintNode() {
		if (head == tail)
			return;

		Node* cur = head->next;
		while (cur != tail) {
			cout << cur->data;
			cur = cur->next;
		}
		cout << cur->data;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	LinkedList list;

	list.Init(s);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		char cmd;
		cin >> cmd;

		char c;
		switch (cmd) {
		case 'L':
			list.Left();
			break;
		case 'D':
			list.Right();
			break;
		case 'B':
			list.Backspace();
			break;
		case 'P':
			cin >> c;
			list.Plus(c);
			break;
		}
	}

	list.PrintNode();
}