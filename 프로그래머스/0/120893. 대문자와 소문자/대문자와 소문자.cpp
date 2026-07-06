#include <string>
using namespace std;

string solution(string my_string) {
    string ans;
    for(int i = 0; i<my_string.size(); i++)
        if ('a' <= my_string[i] && my_string[i] <= 'z')
            ans.push_back(my_string[i] - 'a' + 'A');
        else
            ans.push_back(my_string[i] - 'A' + 'a');
    return ans;
}