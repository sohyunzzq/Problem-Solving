/*
[수학]

양쪽이 대칭이고
남는 날들은
현재 늘린 키보다 작으면 어떻게든 끼워서 뺄 수 있음
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
		// 시작부터 키가 같음
		if (days == 0)
			break;

		left++;
		days -= left;
		ans++;

		// 뺐더니 키가 같아졌으면 바로 빠이
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