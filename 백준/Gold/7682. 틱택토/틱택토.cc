/*
[시뮬레이션]

X가 선공
종료 조건: 3칸 잇기 or 게임판 가득 차기

1. 가능한 상황
cnt_x == cnt_o + 1: X가 이겼거나 판이 꽉 참
cnt_x == cnt_o: 무조건 O가 이긴 상황만 가능

1-1. 누군가 이긴 경우
이긴 즉시 종료해야 함
행/열에서 누군가 이겼으면, 다른 행/열에서 또 다른 승리 조건이 있으면 안 됨

1-2. 판이 꽉 찬 경우
누군가 이긴 건 미리 처리될 것임
무승부로 끝나도 valid
*/

#include <iostream>
using namespace std;

char board[3][3];

int GetWinner() {
    // X가 이기면 1, O가 이기면 2, 무승부 0
    int win = -1;

    int cnt;
    
    // 가로가 전부 같음
    cnt = 0;
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] &&
            board[row][1] == board[row][2] &&
            board[row][2] != '.') {
            if (board[row][0] == 'X')
                win = 1;
            else
                win = 2;
            cnt++;
        }
    }

    if (cnt > 1)
        return -1;

    // 세로가 전부 같음
    cnt = 0;
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] &&
            board[1][col] == board[2][col] &&
            board[2][col] != '.') {
            if (board[0][col] == 'X')
                win = 1;
            else
                win = 2;
            cnt++;
        }
    }

    if (cnt > 1)
        return -1;

    // 대각선이 전부 같음
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[2][2] != '.') {
        if (board[0][0] == 'X')
            win = 1;
        else
            win = 2;
    }

    // 대각선이 전부 같음
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
        board[2][0] != '.') {
        if (board[0][2] == 'X')
            win = 1;
        else
            win = 2;
    }

    // 무승부
    bool tmp = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '.') {
                tmp = false;
                break;
            }
        }
    }
    if (tmp && win == -1)
        win = 0;

    return win;
}

void Setting(string* str, int* x, int* o) {
    int index = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if ((*str)[index] == 'X')
                (*x)++;
            else if ((*str)[index] == 'O')
                (*o)++;

            board[i][j] = (*str)[index++];
        }
}

int main() {
    while (1) {
        string str;
        cin >> str;
        if (str == "end")
            break;

        int cnt_x = 0, cnt_o = 0;
        Setting(&str, &cnt_x, &cnt_o);

        bool possible_flag = false;

        int winner = GetWinner();

        // O가 더 많거나 X가 2개 이상 많음
        if ((cnt_x < cnt_o) || (abs(cnt_x - cnt_o) > 1))
            ;
        // x가 이김
        else if ((cnt_x == cnt_o + 1) && (winner == 1))
            possible_flag = true;
        // 무승부 (판 꽉 참)
        else if ((cnt_x == cnt_o + 1) && (winner == 0))
            possible_flag = true;
        // o가 이김
        else if ((cnt_x == cnt_o) && (winner == 2))
            possible_flag = true;

        cout << (possible_flag ? "valid" : "invalid") << endl;
    }
}