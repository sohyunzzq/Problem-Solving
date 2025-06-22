#include <iostream>
#include <vector>

using namespace std;

#define NODE_SZ 5000
#define endl '\n'

struct Node {
	int data;
	Node* next;

	Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
	Node* head;
	Node* tail;
	vector<Node*> Nodes;
	int NodeCnt;

public:
	LinkedList() : head(nullptr), tail(nullptr), NodeCnt(0) {
		Nodes.resize(NODE_SZ, nullptr);
	}

	Node* MakeNode(int data) {
		return Nodes[NodeCnt++] = new Node(data);
	}

	void Insert(int index, vector<int> nums) {
		int start = 0;

		if (index == 0) {
			if (head == nullptr) {
				head = MakeNode(nums[0]);
			}
			else {
				Node* temp = MakeNode(nums[0]);
				temp->next = head;
				head = temp;
			}
			index++;
			start++;
		}

		Node* cur = head;
		for (int i = 1; i < index; i++)
			cur = cur->next;

		for (int i = start; i < nums.size(); i++) {
			Node* temp = MakeNode(nums[i]);
			temp->next = cur->next;
			cur->next = temp;
			cur = temp;
		}

		if (cur->next == nullptr)
			tail = cur;
	}

	void Delete(int index, int cnt) {
		Node* cur = head;
		if (index == 0) {
			for (int i = 0; i < cnt; i++)
				cur = cur->next;
			head = cur;
			return;
		}

		for (int i = 1; i < index; i++)
			cur = cur->next;
		Node* temp = cur;

		for (int i = 0; i < cnt; i++)
			cur = cur->next;

		temp->next = cur->next;

		if (temp->next == nullptr)
			tail = temp;
	}

	void Add(int data) {
		Node* temp = MakeNode(data);
		tail->next = temp;
		tail = temp;
	}

	void Print() {
		Node* cur = head;
		for (int i = 0; i < 10; i++) {
			cout << cur->data << " ";
			cur = cur->next;
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int tc = 1; tc <= 10; tc++) {
		LinkedList list;

		// 첫 번째 줄
		int n;
		cin >> n;

		// 두 번째 줄
		vector<int> nums(n);
		for (int i = 0; i < n; i++)
			cin >> nums[i];
		list.Insert(0, nums);

		// 세 번째 줄
		int m;
		cin >> m;

		// 네 번째 줄
		for (int i = 0; i < m; i++) {
			char cmd;
			cin >> cmd;

			vector<int> nums2;
			int x, y, s;
			switch (cmd) {
			case 'I': {
				cin >> x >> y;
				nums2.resize(y);
				for (int j = 0; j < y; j++) {
					cin >> nums2[j];
				}
				list.Insert(x, nums2);
				break;
			}
			case 'D': {
				cin >> x >> y;
				list.Delete(x, y);
				break;
			}
			case 'A': {
				cin >> y;
				for (int j = 0; j < y; j++) {
					int num;
					cin >> num;

					list.Add(num);
				}
				break;
			}
			}
		}
		cout << "#" << tc << " ";
		list.Print();
		cout << endl;
	}
}