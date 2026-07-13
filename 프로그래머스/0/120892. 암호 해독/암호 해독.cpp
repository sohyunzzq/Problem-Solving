#include <string>
using namespace std;

string solution(string cipher, int code) {
    string ans = "";
    for (int i=code-1; i<cipher.size(); i+=code)
        ans += cipher[i];
    return ans;
}