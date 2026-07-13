#include <string>
using namespace std;

int solution(string n_str) {
    int num = 0;
    for (int i=0; i<n_str.size(); i++) {
        num *= 10;
        num += int(n_str[i] - '0');
    }
    return num;
}