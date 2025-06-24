#include <iostream>
#include <vector>
using namespace std;

#define NODE_CNT 500001
#define endl '\n'

struct Node {
	long long data;
	Node* prev;
	Node* next;
	int pos;

	Node(long long data, int pos) :data(data), prev(nullptr), next(nullptr), pos(pos) {}
};

class LinkedList {
	Node* head;
	Node* tail;
	vector<Node*> Nodes;
	int cnt;

public:
	LinkedList() :head(nullptr), tail(nullptr), cnt(0) {
		Nodes.resize(NODE_CNT, nullptr);
	}

	Node* MakeNode(long long data, int pos) {
		return Nodes[cnt++] = new Node(data, pos);
	}

	void Init(vector<int> nums) {
		head = MakeNode(nums[0], 1);
		tail = head;

		Node* cur = head;
		for (int i = 1; i < nums.size(); i++) {
			Node* temp = MakeNode(nums[i], i + 1);
			cur->next = temp;
			temp->prev = cur;
			cur = temp;
			tail = temp;
		}
	}

	void Eat() {
		while (1) {
			if (head == tail)
				return;

			Node* cur = head;

			// head
			// 다음 거 잡아먹기
			if (cur->data >= cur->next->data) {
				cur->data += cur->next->data;

				if (cur->next == tail) {
					tail = cur;
					return;
				}

				Node* temp = cur->next->next;
				cur->next = temp;
				temp->prev = cur;

			}
			cur = cur->next;

			bool changed = false;
			while (cur != tail) {
				// 직전 거 잡아먹기
				long long original = cur->data;

				if (original >= cur->prev->data) {
					cur->data += cur->prev->data;

					if (cur->prev == head) {
						head = cur;
					}
					else {
						Node* temp = cur->prev->prev;
						temp->next = cur;
						cur->prev = temp;
					}
				}

				// 다음 거 잡아먹기
				if (original >= cur->next->data) {
					cur->data += cur->next->data;

					if (cur->next == tail) {
						tail = cur;
					}
					else {
						Node* temp = cur->next->next;
						cur->next = temp;
						temp->prev = cur;
					}
				}

				if (head == tail)
					return;

				// tail이 잡아먹혀서 갱신됨
				if (cur == tail) {
					changed = true;
					break;
				}

				cur = cur->next;
			} ////////// 몸통 while

			// tail이 잡아먹힘
			if (changed)
				continue;

			// tail
			// 직전 거 잡아먹기
			if (cur->data >= cur->prev->data) {
				cur->data += cur->prev->data;

				if (cur->prev == head) {
					head = cur;
					return;
				}
				Node* temp = cur->prev->prev;
				temp->next = cur;
				cur->prev = temp;
			}
		}
	}

	void Print() {
		cout << head->data << endl << head->pos;
	}
};

int main() {
	int n;
	cin >> n;

	LinkedList list;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	list.Init(nums);
	list.Eat();
	list.Print();
}