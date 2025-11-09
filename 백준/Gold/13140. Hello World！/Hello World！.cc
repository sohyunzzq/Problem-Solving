#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define endl '\n'

vector<int> alpha;
bool used[10];
int n;
bool flag = false;

int Cal() {
	int result = 0;

	// hello
	result += alpha[0] * 10000
		+ alpha[1] * 1000
		+ alpha[2] * 110
		+ alpha[3];
	
	// world
	result += alpha[4] * 10000
		+ alpha[3] * 1000
		+ alpha[5] * 100
		+ alpha[2] * 10
		+ alpha[6];

	return result;
}

void Print() {
	cout << "  " << alpha[0] << alpha[1] << alpha[2] << alpha[2] << alpha[3] << endl;
	cout << "+ " << alpha[4] << alpha[3] << alpha[5] << alpha[2] << alpha[6] << endl;
	cout << "-------" << endl;

	for (int i = 0; i < 7 - to_string(n).size(); i++)
		cout << " ";
	cout << to_string(n);
}

void func(int curr) {
	if (curr == 7) {
		int result = Cal();

		if (result == n) {
			Print();
			flag = true;
		}

		return;
	}

	for (int i = 0; i < 10; i++) {
		// h와 w에는 0이 올 수 없다
		if (i == 0 && (curr == 0 || curr == 4))
			continue;

		if (used[i])
			continue;

		alpha.push_back(i);
		used[i] = true;

		func(curr + 1);
		
		if (flag)
			return;

		alpha.pop_back();
		used[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	// 하나씩 넣으면 되나 ㅎㅎ

	cin >> n;

	func(0);

	if (!flag)
		cout << "No Answer";
}