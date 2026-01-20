#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	double sum_num = 0;
	double sum_score = 0;
	for (int i = 0; i < 20; i++) {
		string s;
		double num;
		string grade;

		cin >> s >> num >> grade;

		sum_num += num;
		if (grade == "A+")
			sum_score += num * 4.5;
		else if (grade == "A0")
			sum_score += num * 4;
		else if (grade == "B+")
			sum_score += num * 3.5;
		else if (grade == "B0")
			sum_score += num * 3;
		else if (grade == "C+")
			sum_score += num * 2.5;
		else if (grade == "C0")
			sum_score += num * 2;
		else if (grade == "D+")
			sum_score += num * 1.5;
		else if (grade == "D0")
			sum_score += num * 1;
		else if (grade == "P")
			sum_num -= num;
	}

	cout << fixed;
	cout.precision(6);

	cout << sum_score / sum_num;
}