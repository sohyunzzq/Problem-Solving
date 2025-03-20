/*
[누적합]
이걸 어케 이분 탐색한다는 건지 잘 모르겟다...
어케 풀어야 하는지 몰라서 물어봄

홀수, 짝수 따로 생각한 다음에 나중에 합쳐주기

홀수: 아래에서 자라는 거
index가 들어오는 값 자체
누적합 구할 때: h부터 1까지

짝수: 위에서 내려오는 거
index가 n+1-들어오는 값
누적합 구할 때: 1부터 h까지
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> odd;
vector<int> even;
vector<int> odd_sum;
vector<int> even_sum;
vector<int> sum;

int main() {
	int n, h;
	cin >> n >> h;

	odd.resize(h + 1);
	even.resize(h + 1);
	sum.resize(h + 1);

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (i % 2 == 1) {
			odd[num]++;
		}
		else {
			even[h + 1 - num]++;
		}
	}

	// 홀수
	for (int i = h; i >= 1; i--) {
		odd[i - 1] += odd[i];
	}
	// 짝수
	for (int i = 1; i <= h; i++) {
		even[i] += even[i - 1];
	}

	int min_val = n + 1, cnt = 0;

	// 합치기
	for (int i = 1; i <= h; i++) {
		sum[i] = odd[i] + even[i];
		min_val = min(min_val, sum[i]);
	}

	for (int i = 1; i <= h; i++) {
		if (sum[i] == min_val)
			cnt++;
	}

	cout << min_val << " " << cnt;
}