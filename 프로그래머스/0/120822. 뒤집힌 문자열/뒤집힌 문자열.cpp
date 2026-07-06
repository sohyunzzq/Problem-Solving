#include <string>

using namespace std;

string solution(string my_string) {
    string ans = "";
    for (int i=0; i<my_string.size(); i++)
        ans.push_back(my_string[my_string.size()-1-i]);
    return ans;
}