/*
[수학]

원숭이는 멍멍이를 쓰다듬고 싶은데
원숭이는 멍멍이보다 키가 작아서 못함
쓰다듬으려면 둘이 키가 같아야 함

원숭이는 하루에 1cm밖에 조절할 수 없음
오늘 5cm 늘렸으면 내일은 4~6 중 하나만큼
키는 양수가 될 수 없음

첫날과 마지막날은 무조건 1cm 늘릴 수 있음
원숭이가 매일 키를 늘려서 멍멍이랑 키가 같아지는 최소 일수
*/

#include <iostream>
using namespace std;

int main() {
	int monkey, dog;
	cin >> monkey >> dog;

	int left = 0, right = 0;
	int days = dog - monkey;
	int ans = 0;

	while (1) {
		if (days == 0)
			break;

		left++;
		days -= left;
		ans++;

		if (days == 0)
			break;

		if (days <= left) {
			ans++;
			break;
		}

		right++;
		days -= right;
		ans++;

		if (days == 0)
			break;

		if (days <= right) {
			ans++;
			break;
		}
	}

	cout << ans;
}