#include <string>
using namespace std;

string solution(string rsp) {
    string ans;
    
    for (int i=0; i<rsp.size(); i++)
        switch (rsp[i]) {
            case '0':
                ans += '5';
                break;
            case '2':
                ans += '0';
                break;
            case '5':
                ans += '2';
                break;
        }
    return ans;
}