#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int h, m;
	cin >> h >> m;

	bool flag = false;
	switch (h) {
	case 6:
		if (m >= 30)
			flag = true;
		break;
	case 7:	case 8:
		flag = true;
		break;
	case 9:	case 10: case 11: case 12:
		if (m == 0 || m >= 50)
			flag = true;
		break;
	case 13:
		if (m <= 50)
			flag = true;
		break;
	case 14: case 15:
		if (40 <= m && m <= 50)
			flag = true;
		break;
	case 16:
		if (m >= 40)
			flag = true;
		break;
	case 17: case 18: case 19: case 20: case 21:
		flag = true;
		break;
	case 22:
		if (m <= 50)
			flag = true;
		break;
	}
	cout << (flag ? "Yes" : "No");
}