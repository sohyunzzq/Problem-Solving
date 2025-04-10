/*
[우선순위 큐]

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<struct Subject> Arr;
priority_queue<struct Subject> q;

struct Subject {
	int score;
	int increase;
	bool operator<(struct Subject right) const {
		return increase < right.increase;
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	Arr.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> Arr[i].score;
		Arr[i].score = 100 - Arr[i].score;
	}
	for (int i = 0; i < m; i++) {
		cin >> Arr[i].increase;
	}

	for (int i = 0; i < m; i++) {
		q.push(Arr[i]);
	}

	int total = 0;

	int hour = 24 * n;
	while (hour && q.size()) {
		struct Subject now = q.top();
		q.pop();

		if (now.score == 0) {
			total += 100;
			continue;
		}
		int tmp = now.score / now.increase;
		if (hour - tmp >= 0) {
			hour -= tmp;
			now.score = now.increase = now.score % now.increase;
			q.push(now);
		}
		else {
			now.score -= now.increase * hour;
			if (now.score < 0)
				now.score = 0;

			hour = 0;
			q.push(now);
		}
	}

	// 큐에서 하나씩 빼면서 점수 더하기
	// 100에서 빼면서 더해줘야 함
	while(q.size()) {
		struct Subject now = q.top();
		q.pop();

		total += 100 - now.score;
	}

	cout << total;
}