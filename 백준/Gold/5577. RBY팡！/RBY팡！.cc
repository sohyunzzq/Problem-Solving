/*
[]

나와 인접한 공의 색으로 바꾸기
바꾼 후 어디까지 체크해야 하는가?

색을 바꾼 후, 위에서부터 체크할 텐데
맨 위에서부터 계속 체크하면 시간 낭비
=> 색깔이 바뀔 때 인덱스를 저장해두기

#1. 위 == 나 == 아래:
바꿀 필요 없음 continue

#2. 위 == 아래:
일단 바꾼 후
인덱스 활용하고, 아래 쭉 내려가보기

#3. 위 != 아래 && 위랑 다름 -> 위로 바꿈:
인덱스를 활용해서 위에서부터 몇 개가 연속됐는지 바로 알 수 있음
만약, 내가 바뀌었을 때 4개 이상이면 바꾸고 아니면 바꿀 필요 없음 continue

#4. 위 != 아래 && 아래랑 다름 -> 아래로 바꿈:
일단 바꿔서 확인하는 게 빠를 듯
아래로 쭉 내려가서 직접 체크
*/

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> origin;
vector<int> balls;
int min_cnt;

void InitBalls() {
	for (int i = 0; i < n; i++)
		balls[i] = origin[i];
}

int GetCnt() {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (balls[i])
			cnt++;
	return cnt;
}

void Pang() {
	bool flag = true;

	while (flag) {
		flag = false;

		vector<int> cnt(n, 1);
		int last_index = 0;
		for (int i = 1; i < n; i++) {
			if (balls[i] == 0) {
				// 공 터뜨릴 때 방해되니 0으로 처리
				cnt[i] = 0;
				continue;
			}

			if (balls[i] == balls[last_index]) {
				cnt[i] += cnt[last_index];
			}
			
			last_index = i;
		}

		for (int i = n - 1; i >= 0; i--) {
			if (cnt[i] >= 4) {
				// 터뜨릴 게 있음
				
				flag = true;
				// i부터 내려가면서 터뜨리기
				while (cnt[i] != 1)
					balls[i--] = 0;
				balls[i] = 0;
				
				break;
			}
		}
	}

	min_cnt = min(min_cnt, GetCnt());
}

void Simulate() {
	// 색깔이 바뀌는 순간의 index
	int index = 0;

	// 0번째 공은 아래로밖에 못 바꿈
	InitBalls();
	balls[0] = origin[1];
	Pang();

	for (int i = 1; i < n - 1; i++) {
		// #1 위 == 나 == 아래
		if (origin[i - 1] == origin[i] && origin[i] == origin[i + 1])
			continue;

		// #2 위 == 아래
		if (origin[i - 1] == origin[i + 1]) {
			InitBalls();
			balls[i] = origin[i - 1];
			Pang();
		}

		// 위 != 아래
		else {
			if (origin[i] != origin[i - 1]) {
				// #3 위 != 나
				if ((i - index) >= 3) {
					// 내가 위랑 색이 같아지면 터질 수 있음
					InitBalls();
					balls[i] = origin[i - 1];
					Pang();
				}
				index++;
			}

			if (origin[i] != origin[i + 1]) {
				// #4 나 != 아래
				InitBalls();
				balls[i] = origin[i + 1];
				Pang();
			}
		}
	}

	// (n-1)번째 공은 위로밖에 못 바꿈
	InitBalls();
	balls[n - 1] = origin[n - 2];
	Pang();
}

int main() {
	cin >> n;
	origin.resize(n);
	balls.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> origin[i];
	}
	
	// 값 초기화
	min_cnt = n;

	// 공이 3개 이하면 확인할 필요 없음
	if (n > 3)
		Simulate();

	cout << min_cnt;
}