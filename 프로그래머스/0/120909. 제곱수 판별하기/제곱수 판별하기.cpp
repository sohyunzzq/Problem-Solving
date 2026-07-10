using namespace std;

int solution(int n) {
    for (int i=n; i>=1; i--)
        if (i * i == n)
            return 1;
    return 2;
}