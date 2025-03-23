/*
N, M 모두 100,000까지임
번호가 들어오면 배열의 인덱스로 처리하면 되지만
이름이 들어오면 O(N^2)까지 감

map 자료구조를 사용해서, 각각 만들자
map은 파이썬의 dictionary와 같음
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int> name;
	map<int, string> index;

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;

		name.insert({ str, i });
		index.insert({ i, str });
	}

	for (int i = 0; i < m; i++) {
		string cmd;
		cin >> cmd;

		if (0 <= cmd[0] - '0' && cmd[0] - '0' <= 9) {
			// 인덱스로 주어지면 이름 출력
			cout << index[stoi(cmd)] << endl;
		}
		else
			cout << name[cmd] << endl;
	}
}