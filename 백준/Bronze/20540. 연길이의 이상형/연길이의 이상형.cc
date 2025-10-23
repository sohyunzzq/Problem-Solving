#include <iostream>
#include <map>
using namespace std;

map<char, char> mbti;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	mbti['E'] = 'I';
	mbti['I'] = 'E';
	mbti['S'] = 'N';
	mbti['N'] = 'S';
	mbti['T'] = 'F';
	mbti['F'] = 'T';
	mbti['J'] = 'P';
	mbti['P'] = 'J';

	string s;
	cin >> s;

	for (char c : s) {
		cout << mbti[c];
	}
}