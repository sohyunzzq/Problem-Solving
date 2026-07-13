#include <string>
using namespace std;

int solution(int num, int k) {
    string s = to_string(num);
    
    for (int i=0; i<s.size(); i++)
        if (s[i] == char(k+'0'))
            return i+1;
    return -1;
}