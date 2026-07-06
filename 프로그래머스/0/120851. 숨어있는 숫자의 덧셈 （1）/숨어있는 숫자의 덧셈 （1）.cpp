#include <string>
using namespace std;

int solution(string my_string) {
    int sum = 0;
    for (int i=0; i<my_string.size(); i++) {
        char c = my_string[i];
        if ('0' <= c && c <= '9')
            sum += int(c - '0');
    }
    return sum;
}