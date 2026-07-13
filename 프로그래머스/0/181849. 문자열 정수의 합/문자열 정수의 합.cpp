#include <string>
using namespace std;

int solution(string num_str) {
    int sum = 0;
    for (int i=0; i<num_str.size(); i++)
        sum += int(num_str[i] - '0');
    return sum;
}