using namespace std;

int solution(int hp) {
    int cnt = 0;
    
    cnt += hp / 5;
    hp %= 5;
    
    cnt += hp / 3;
    hp %= 3;
    
    cnt += hp;
    
    return cnt;
}