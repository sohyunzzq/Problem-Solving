#include <string>
using namespace std;

string solution(string my_string, string letter) {
    string ans;
    for (int i=0; i<my_string.size(); i++)
        if (my_string[i] == letter[0])
            continue;
        else
            ans.push_back(my_string[i]);
    
    return ans;
}