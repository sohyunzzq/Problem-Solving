#include <string>
using namespace std;

string solution(string n_str) {
    string ans;
    int idx = 0;
    while(idx < n_str.size() && n_str[idx] == '0')
        idx++;
    while(idx < n_str.size())
        ans += n_str[idx++];
    return ans;
}