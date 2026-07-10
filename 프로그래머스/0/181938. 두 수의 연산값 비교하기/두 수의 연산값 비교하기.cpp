#include <string>
using namespace std;

int solution(int a, int b) {
    string str_ab = to_string(a) + to_string(b);
    int ab2 = 2*a*b;
    
    int ab = stoi(str_ab);
    
    return max(ab2, ab);
}