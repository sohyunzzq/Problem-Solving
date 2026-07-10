#include <string>
using namespace std;

string solution(string my_string, int n) {
    string ans;
    for (int i=0; i<n; i++)
        ans += my_string[i];
    return ans;
}