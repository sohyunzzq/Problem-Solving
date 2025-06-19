#include <iostream>
#include <vector>
using namespace std;

struct Student {
	int num;
	int score;
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> scores(n);
	for (int i = 0; i < n; i++)
		cin >> scores[i];

	int stu_num;
	int max_score = 0;

	vector<Student> students(m);
	for (int i = 0; i < m; i++) {
		cin >> students[i].num;
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == 'O')
				students[i].score += scores[j];
		}
		if (students[i].score > max_score) {
			max_score = students[i].score;
			stu_num = students[i].num;
		}
		else if (students[i].score == max_score)
			stu_num = min(stu_num, students[i].num);
	}

	cout << stu_num << " " << max_score;
}