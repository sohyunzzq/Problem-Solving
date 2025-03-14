/*
[시뮬레이션, 덱]

파이썬으로 풀었다가 틀렸던 문제
정말 끔.찍.해.

사과: 뱀 길이 늘어남
벽/자기랑 부딪히면 게임 끝남

머리 먼저 움직여야 한다는 걸 생각하기

덱을 써야 함!!
원소를 넣고 빼는 경우를 잘 생각해야 함
머리를 업데이트할 때는 머리를 팝하지 않아도 됨 + 새로운 머리 푸쉬
꼬리는 경우에 따라 팝
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Cmd {
	int t;
	char dir;
};

int n;
vector<vector<int>> board;
int dr = 1;
deque<pair<int, int>> snake;
vector<struct Cmd> cmds;
int now;
bool EndFlag;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool in_range(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void Move() {
	// dr 방향으로 1칸 가기

	// 머리 먼저 이동 후 꼬리 이동

	// 머리
	pair<int, int> head = snake.front();

	int x = head.first;
	int y = head.second;
	int nx = x + dx[dr];
	int ny = y + dy[dr];
	
	// 벽에 부딪힘
	if (!in_range(nx, ny)) {
		EndFlag = true;
		return;
	}

	// 내 몸에 부딪힘
	if (board[nx][ny] == 1) {
		EndFlag = true;
		return;
	}

	// 사과 있음
	if (board[nx][ny] == 10) {
		// 사과 없애
		// 새로운 머리 넣어주기
		// 꼬리는 이동할 필요 없이 리턴
		
		board[nx][ny] = 1;
		snake.push_front({ nx, ny });
		return;
	}

	// 사과 없음
	
	// 새로운 머리 넣기
	// 꼬리 없애기
	board[nx][ny] = 1;
	snake.push_front({ nx, ny });
	pair<int, int> tail = snake.back();
	snake.pop_back();
	board[tail.first][tail.second] = 0;
}

int main() {
	cin >> n;
	board.resize(n);
	for (int i = 0; i < n; i++) {
		board[i].resize(n);
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		
		// 사과는 10으로 표시
		board[x - 1][y - 1] = 10;
	}
	int l;
	cin >> l;
	cmds.resize(l);
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		
		cmds[i] = { x, c };
	}

	int index = 0;
	struct Cmd cmd;
	cmd = cmds[index++];

	snake.push_back({ 0, 0 });
	board[0][0] = 1;

	// 이제 게임 시작할 거임
	while (1) {
		// 벽에 부딪혔거나 내 몸에 닿으면 바로 종료
 		if (EndFlag) {
			cout << now;
			break;
		}

		// 커맨드에서 하나씩 꺼내면서
		// 지금 시간이랑 비교함
		
		// 지금 시간이 커맨드 시간보다 작음
		if (now < cmd.t || now > cmd.t) {
			// 가던 대로 가기
			Move();
			now++;
		}
		// 지금 시간이 커맨드 시간임
		else if (now == cmd.t) {
			// 방향 바꾸기
			if (cmd.dir == 'L')
				dr = (dr - 1 + 4) % 4;
			else
				dr = (dr + 1) % 4;

			Move();
			now++;
			
			// 다음 커맨드 못 꺼내면
			if (index >= l) {
				continue;
			}
			cmd = cmds[index++];
		}
	}
}