/*
대문자, 소문자, 숫자, 백스페이스, 화살표

커서의 위치는 비밀번호 길이 + 1
|ab
a|b
ab|

cursor는 내 왼쪽 문자를 가리키는 거로 하고,
맨 앞에 더미노드 추가, 문자는 *으로 표시
*/

#include <iostream>
#include <vector>
using namespace std;

#define NODE_SZ 1000001
#define endl '\n'

struct Node {
	char data;
	Node* prev;
	Node* next;

	Node (char data) : data(data), prev(nullptr), next(nullptr) {}
};

Node* cur;

class LinkedList {
	Node* head;
	Node* tail;
	vector<Node*> Nodes;
	int cnt;

public:
	LinkedList() :head(nullptr), tail(nullptr), cnt(0) {
		Nodes.resize(NODE_SZ, nullptr);
	}

	Node* MakeNode(char data) {
		return Nodes[cnt++] = new Node(data);
	}

	void Init(char data) {
		head = MakeNode('*');
		tail = head;
		cur = head;
	}

	// 현재 커서 뒤에 추가
	void Insert(char data) {
		Node* temp = MakeNode(data);
		
		if (cur == tail) {
			temp->prev = cur;

			cur->next = temp;
			cur = temp;
			tail = temp;
			return;
		}
		
		temp->prev = cur;
		temp->next = cur->next;
		cur->next->prev = temp;
		cur->next = temp;
		cur = temp;
	}

	void Backspace() {
		if (cur == head)
			return;

		if (cur == tail) {
			cur->prev->next = nullptr;
			cur = cur->prev;
			tail = cur;
			return;
		}

		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		cur = cur->prev;
	}

	void Left() {
		if (cur == head)
			return;

		cur = cur->prev;
	}

	void Right() {
		if (cur == tail)
			return;

		cur = cur->next;
	}

	void Print() {
		if (head == tail)
			return;

		Node* temp = head->next;
		
		while (temp != tail) {
			cout << temp->data;
			temp = temp->next;
		}
		cout << temp->data;
	}
};

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		string s;
		cin >> s;

		LinkedList list;
		
		list.Init('*');

		for (int i = 0; s[i]; i++) {
			char cmd = s[i];

			switch (cmd) {
			case '-':
				list.Backspace();
				break;
			case '<':
				list.Left();
				break;
			case '>':
				list.Right();
				break;
			default:
				list.Insert(cmd);
			}
		}
		list.Print();
		cout << endl;
	}
}