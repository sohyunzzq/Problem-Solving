#include <string>
#include <algorithm>
using namespace std;

string solution(string my_string) {
    string ans;
    for (int i=0; i<my_string.size(); i++) {
        if ('A' <= my_string[i] && my_string[i] <= 'Z')
            my_string[i] = my_string[i] - 'A' + 'a';
        ans += my_string[i];
    }
    sort(ans.begin(), ans.end());
    return ans;
}