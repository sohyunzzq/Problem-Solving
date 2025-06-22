#include <iostream>
#include <vector>

using namespace std;

int NODE_MAX = 5000;

struct Node {
	int data;
	Node* next;

	Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
	Node* head;
	Node* tail;
	vector<Node*> NodeArr;
	int NodeCnt;

public:
	LinkedList() : head(nullptr), tail(nullptr), NodeCnt(0) {
		NodeArr.resize(NODE_MAX, nullptr);
	}

	Node* GetNewNode(int data) {
		return NodeArr[NodeCnt++] = new Node(data);
	}

	void InsertNum(int index, vector<int> nums) {
		int start = 0;

		// 맨 앞부터 넣으래
		if (index == 0) {
			// 초기 상태
			if (head == nullptr) {
				Node* newnode = GetNewNode(nums[0]);
				head = newnode;
			}
			else {
				Node* newnode = GetNewNode(nums[0]);
				newnode->next = head;
				head = newnode;
			}
			index++;
			start++;
		}

		Node* cur = head;
		for (int i = 1; i < index; i++)
			cur = cur->next;

		for (int i = start; i < nums.size(); i++) {
			Node* newnode = GetNewNode(nums[i]);
			newnode->next = cur->next;
			cur->next = newnode;
			cur = newnode;
		}

		if (cur->next == nullptr)
			tail = cur;
	}

	void DeleteNodes(int index, int cnt) {
		Node* cur = head;
		// 헤드를 없애래
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

	void AddTail(int data) {
		Node* newnode = GetNewNode(data);
		tail->next = newnode;
		tail = newnode;
	}

	void PrintList(int cnt) {
		Node* cur = head;
		for (int i = 0; i < cnt; i++) {
			cout << cur->data << " ";
			cur = cur->next;
		}
	}
};

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		LinkedList list;
		
		// 첫 번째 줄
		int n;
		cin >> n;

		// 두 번째 줄
		vector<int> nums(n);
		for (int i = 0; i < n; i++)
			cin >> nums[i];
		list.InsertNum(0, nums);

		// 세 번째 줄
		int m;
		cin >> m;

		// 네 번째 줄
		for (int i = 0; i < m; i++) {
			char c;
			cin >> c;

			switch (c) {
			case 'I': {
				int index, y;
				cin >> index >> y;

				vector<int> nums2(y);
				for (int j = 0; j < y; j++)
					cin >> nums2[j];

				list.InsertNum(index, nums2);
				break;
			}
			case 'D': {
				int x, y;
				cin >> x >> y;

				list.DeleteNodes(x, y);
				break;
			}
			case 'A': {
				int y;
				cin >> y;

				for (int j = 0; j < y; j++) {
					int num;
					cin >> num;

					list.AddTail(num);
				}
				break;
			}
			}
		}

		cout << "#" << tc << " ";
		list.PrintList(10);
		cout << endl;
	}
}