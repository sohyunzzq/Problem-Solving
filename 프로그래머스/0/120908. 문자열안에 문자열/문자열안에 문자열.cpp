#include <string>
using namespace std;

int solution(string str1, string str2) {
    bool flag = false;
    for (int i=0; i<str1.size(); i++) {
        if (str1[i] == str2[0]) {
            flag = true;
            for (int j=1; j<str2.size(); j++) {
                if (str1[i+j] != str2[j]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            return 1;
    }
    return (flag?1:2);
}