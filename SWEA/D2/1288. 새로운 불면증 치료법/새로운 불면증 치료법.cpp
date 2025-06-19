/*
0~9 표시할 배열 필요 -> 10비트
int 4바이트 = 32bits
*/

#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;

		int k = 1;
		int num = 0;
		while(1){
			int kn = k * n;
			
			while (kn) {
				num |= (1 << kn % 10);
				kn /= 10;
			}

			int bit = (1 << 10) - 1;
			if ((num & bit) == bit) {
				break;
			}
			k++;
		}

		cout << "#" << tc << " " << k * n << endl;
	}
}