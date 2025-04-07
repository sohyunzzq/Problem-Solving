/*
[시뮬레이션]

블랙홀이 있는 칸을 만나거나 항성계를 벗어나면 종료
어느 방향으로 보내야 제일 긴 시간이 걸리는지

방향 행성 최종
 0, 1 /  1, 0
 2, 3 /  3, 2

 0, 3 \ 3, 0
 1, 2 \ 2, 1

무한대로 도는 걸 어떻게 알아챌 건지?
각 칸마다 마지막으로 지나간 방향을 저장해두는 배열을 만들자
*/

#include <iostream>
using namespace std;

#define endl '\n'
#define SZ 550

int n, m;
char area[SZ][SZ];
char last_dr[SZ][SZ];
int pr, pc;
int ans_dr;
int ans_t = 0;
bool VoyagerFlag = false;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
string direction = "URDL";

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void Simulation(int origin_dr) {
	// dr 방향으로 출발
	int x = pr;
	int y = pc;
	int dr = origin_dr;

	VoyagerFlag = false;

	int t = 0;
	while (1) {
		t++;
		int nx = x + dx[dr];
		int ny = y + dy[dr];

		// 종료 조건: 범위 벗어나거나 블랙홀 만남
		if (!InRange(nx, ny) || area[nx][ny] == 'C') {
			if (t > ans_t) {
				ans_t = t;
				ans_dr = origin_dr;
			}
			return;
		}

		// 이미 같은 루트로 지나갔음
		if (last_dr[nx][ny] == dr) {
			VoyagerFlag = true;
			ans_dr = origin_dr;
			return;
		}

		last_dr[nx][ny] = dr;

		if (area[nx][ny] == '/') {
			// 0번 비트를 토글
			dr ^= 1;
		}
		else if (area[nx][ny] == '\\') {
			dr ^= 0b11;
		}

		x = nx;
		y = ny;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> area[i][j];
		}
	}
	cin >> pr >> pc;
	pr--; pc--;

	for (int dr = 0; dr < 4; dr++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				last_dr[i][j] = -1;
			}
		}

		Simulation(dr);
		
		// 반복되면 바로 종료
		if (VoyagerFlag) {
			cout << direction[ans_dr] << endl << "Voyager";
			break;
		}
	}

	if (!VoyagerFlag) {
		cout << direction[ans_dr] << endl << ans_t;
	}
}