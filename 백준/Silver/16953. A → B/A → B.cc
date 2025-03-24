/*
거꾸로 생각하기
B -> A로 가면 됨

현재 숫자의 맨 마지막이 1이라면 1을 제거해주기
아니면 2로 나눠주기
A보다 작아지면 불가능하니 즉시 종료
*/

#include <iostream>
using namespace std;

#define endl '\n'

int main() {
	int a, b;
	cin >> a >> b;

	int cnt = 0;
	while (a < b) {
		if (b % 10 == 1) {
			b /= 10;
		}
		else if (b % 2 == 0) {
			b /= 2;
		}
		else
			break;
		cnt++;
	}

	cout << (a == b ? cnt + 1 : -1);
}